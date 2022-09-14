
// #define __USE_GNU


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int firstEnter = 1;

extern void *__libc_malloc(size_t size);
static int enable_malloc_hook = 1;

extern void __libc_free(void *p);
static int enable_free_hook = 1;

#if 0
void *malloc(size_t size) 
{
    if (enable_malloc_hook) {
        enable_malloc_hook = 0;
        void *p = __libc_malloc(size);

        void *caller = __builtin_return_address(1);
        char buff[128] = {0};
        sprintf(buff, "./mem/%p.mem", p);

        FILE *fp = fopen(buff, "w");
        fprintf(fp, "[+%p] ---> addr %pm size:%ld", caller, p, size);
        fflush(fp);
        enable_malloc_hook = 1;
        return p;
    } else {
        return __libc_malloc(size);
    }
}

void free(void *p)
{
    if (enable_free_hook) {
        enable_free_hook = 0;
        char buff[128] = {0};
        sprintf(buff, "./mem/%p.mem", p);
        if (unlink(buff) < 0) {
            printf("double free: %p\n", p);
        }
        __libc_free(p);
        enable_free_hook = 1;
    } else {
        __libc_free(p);       
    }
}
#endif
 
void *malloc_hook(size_t size, const char *file, int line) 
{
    void *p = malloc(size);
    char buff[128] = {0};
    sprintf(buff, "./mem/%p.mem", p);
    FILE *fp = fopen(buff, "w");
    fprintf(fp, "[+%s:%d] ---> addr %p size:%ld", file, line, p, size);
    fclose(fp);

    return p;
}

void free_hook(void *p) 
{
    char buff[128] = {0};
    sprintf(buff, "./mem/%p.mem", p);
    if (unlink(buff) < 0) {
        printf("double free: %p\n", p);
    }
    free(p);
}

#define malloc(size)    malloc_hook(size, __FILE__, __LINE__)
#define free(p)         free_hook(p)


#if 1
typedef void *(*malloc_hook_t)(size_t size, const void *caller);
malloc_hook_t malloc_f;

typedef void (*free_hook_t)(void *p, const void *caller);
free_hook_t free_f;

int replaced = 0;

void *malloc_hook_f(size_t size, const void *caller) {

	mem_untrace();
	void *ptr = malloc(size);
	//printf("+%p: addr[%p]\n", caller, ptr);

	char buff[128] = {0};
	sprintf(buff, "./mem/%p.mem", ptr);

	FILE *fp = fopen(buff, "w");
	fprintf(fp, "[+%p] --> addr:%p, size:%ld\n", caller, ptr, size);
	fflush(fp);

	fclose(fp); //free
	
	mem_trace();
		
	return ptr;
	
}

void *free_hook_f(void *p, const void *caller) {

	mem_untrace();
	//printf("-%p: addr[%p]\n", caller, p);

	char buff[128] = {0};
	sprintf(buff, "./mem/%p.mem", p);

	if (unlink(buff) < 0) { // no exist
		printf("double free: %p\n", p);
		return ;
	}
	
	free(p);
	mem_trace();
	
}

typedef void *(*malloc_hook_t)(size_t size, const void *caller);
malloc_hook_t malloc_f;

typedef void (*free_hook_t)(void *p, const void *caller);
free_hook_t free_f;

void mem_trace(void) { //mtrace

	replaced = 1;
	malloc_f = __malloc_hook; //malloc --> 
	free_f = __free_hook;

	__malloc_hook = malloc_hook_f;
	__free_hook = free_hook_f;
}

void mem_untrace(void) {
	
	__malloc_hook = malloc_f;
	__free_hook = free_f;
	replaced = 0;
}

#endif


int main(int argc, char *argv[]) 
{
    void *p1 = malloc(10);
    void *p2 = malloc(20);
    
    free(p1);
    // free(p2);
    return 0;
}
