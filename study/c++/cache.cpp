#include <iostream>
#include <pthread.h>
#include <chrono>

#define NUM 1000000000 // 10亿

struct Item
{
    Item() : a(0), b(0) {}

    int a;
    int64_t align[8];
    int b;
};

void* Run1(void* args)
{
    Item* item = (Item*)args;
    for (int i = 0; i < NUM; ++i)
    {
        item->a += 1;
    }
    return NULL;
}

void* Run2(void* args)
{
    Item* item = (Item*)args;
    for (int i = 0; i < NUM; ++i)
    {
        item->b += 1;
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    Item item;

    const auto& start = std::chrono::high_resolution_clock::now();
 
    pthread_create(&thread1, NULL, Run1, &item);
    pthread_create(&thread2, NULL, Run2, &item);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    const auto& end = std::chrono::high_resolution_clock::now();
    double ts = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    ts *= 1e-6;//1ms = 1,000,000 ns
    std::cout << "Time cost : " << ts << "ms" << std::endl;
    return 0;
}