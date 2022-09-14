#ifndef _SMALLHEAP_H_
#define _SMALLHEAP_H_

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

    SmallHeapNode TackFirst();
    void AddNode(const SmallHeapNode &node);
    void RemoveNode(const SmallHeapNode &node);
    void Traverse();
private:
    void UpBalance(int index);
    void DownBalance(int index);
private:
    std::vector<SmallHeapNode> nodes_;   
};

#endif