#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <jemalloc/jemalloc.h>

 // 如果打印，一定要用fprintf(stderr)，否则会产生无限循环，因为fprintf(stdout)也会使用malloc！

extern void* __libc_calloc(size_t, size_t);

static void* (*hook_malloc)(size_t) = NULL;
static void* (*hook_calloc)(size_t, size_t) = NULL;
static void* (*hook_realloc)(void *, size_t) = NULL;
static void (*hook_free)(void *) = NULL;

static void init_hook_malloc()
{
    hook_malloc = dlsym(RTLD_NEXT, "je_malloc");
    
    if (!hook_malloc) {
        fprintf(stderr, "init_hook_malloc failed!\n");
        exit(1);
    }

    fprintf(stderr, "init_hook_malloc successfully!\n");
}

static void init_hook_calloc()
{
    hook_calloc = dlsym(RTLD_NEXT, "je_calloc");
    
    if (!hook_calloc) {
        fprintf(stderr, "init_hook_calloc failed!\n");
        exit(1);
    }

    fprintf(stderr, "init_hook_calloc successfully!\n");
}

static void init_hook_realloc()
{
    hook_realloc = dlsym(RTLD_NEXT, "je_realloc");
    
    if (!hook_realloc) {
        fprintf(stderr, "init_hook_realloc failed!\n");
        exit(1);
    }

    fprintf(stderr, "init_hook_realloc successfully!\n");
}

static void init_hook_free()
{
    hook_free = dlsym(RTLD_NEXT, "je_free");
    
    if (!hook_free) {
        fprintf(stderr, "init_hook_free failed!\n");
        exit(1);
    }

    fprintf(stderr, "init_hook_free successfully!\n");
}

void *malloc(size_t size)
{
    if (!hook_malloc) {
        init_hook_malloc();
    }
    void *ret = hook_malloc(size);
    // fprintf(stderr, "hook_malloc: size = %ld, pointer = %p\n", size, ret);

    return ret;
}

void *calloc(size_t nitems, size_t size)
{
    if (!hook_malloc) {
        return __libc_calloc(nitems, size);
    }

    if (!hook_calloc) {
        init_hook_calloc();
    }
    void *ret = hook_calloc(nitems, size);
    // fprintf(stderr, "hook_calloc: size = %ld, pointer = %p\n", size, ret);

    return ret;
}

void *realloc(void *ptr, size_t size)
{
    if (!hook_realloc) {
        init_hook_realloc();
    }
    void *ret = hook_realloc(ptr, size);
    // fprintf(stderr, "hook_realloc: size = %ld, pointer = %p\n", size, ret);

    return ret;
}

void free(void *ptr)
{
    if (!hook_free) {
        init_hook_free();
    }

    hook_free(ptr);
    // fprintf(stderr, "hook_free: pointer = %p\n", ptr);
}

