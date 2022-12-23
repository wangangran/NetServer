#ifndef NETSERVER_REACTOR_DATASTRUCT_SMALLHEAP_H
#define NETSERVER_REACTOR_DATASTRUCT_SMALLHEAP_H

#include <vector>
#include <functional>

using TimeFun = std::function<void()>;

typedef struct SmallHeapNode {
    SmallHeapNode(unsigned int msend) : msencond(msend) {}
    unsigned int msencond;
    TimeFun fun;
    bool operator==(const SmallHeapNode &other) {
        return (this->msencond == other.msencond);
    };
} SmallHeapNode;


class SmallHeap {
public:
    explicit SmallHeap();

    SmallHeapNode tackFirst();
    void addNode(const SmallHeapNode &node);
    void removeNode(const SmallHeapNode &node);
    void traverse();
private:
    void upBalance(int index);
    void downBalance(int index);
private:
    std::vector<SmallHeapNode> nodes_;   
};

#endif // NETSERVER_REACTOR_DATASTRUCT_SMALLHEAP_H