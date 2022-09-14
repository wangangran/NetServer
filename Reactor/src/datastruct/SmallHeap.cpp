#include "SmallHeap.h"
#include <iostream>

#define PARENT_INDEX(i)             ((i - 1) / 2)
#define LEFT_CHILD_INDEX(i)         (2 * i + 1)
#define RIGHT_CHILD_INDEX(i)        (2 * i + 2)

SmallHeap::SmallHeap()
{

}

SmallHeapNode SmallHeap::TackFirst()
{
    if (nodes_.empty()) return SmallHeapNode(0);
    int index = 0;
    SmallHeapNode node = nodes_[0];
    std::swap(nodes_[0], nodes_[nodes_.size() - 1]);      
    nodes_.pop_back();    
    DownBalance(0);
    return node;
}

void SmallHeap::AddNode(const SmallHeapNode &node)
{
    nodes_.push_back(node);
    UpBalance(nodes_.size() - 1);
}

void SmallHeap::RemoveNode(const SmallHeapNode &node)
{
    if (nodes_.empty()) return;
    
    int index = 0;
    do {
        if (nodes_[nodes_.size()] == node) {
            break;
        }


        for (index = 0; index < nodes_.size(); ++index) {
            if (nodes_[index] == node) {
                std::swap(nodes_[index], nodes_[nodes_.size() - 1]);      
                nodes_.pop_back();    
                break;
            }
        }
        return;
    } while(false);

    UpBalance(index);
    DownBalance(index);
}

void SmallHeap::Traverse()
{
    for (auto ite = nodes_.begin(); ite != nodes_.end(); ++ite) {
        std::cout << ite->msencond << std::endl;
    }
}

void SmallHeap::UpBalance(int index)
{
    if (index <= 0) {
        return;
    }

    int parentIndex = PARENT_INDEX(index);
    if (nodes_[index].msencond < nodes_[parentIndex].msencond) {
        std::swap(nodes_[index], nodes_[parentIndex]);
    }

    UpBalance(parentIndex);
}

void SmallHeap::DownBalance(int index) 
{
    if (LEFT_CHILD_INDEX(index) + 1 > nodes_.size()) {
        return;
    }

    int nextIndex = nodes_.size();
    int leftIndex = LEFT_CHILD_INDEX(index);
    int rightIndex = RIGHT_CHILD_INDEX(index);
    if (rightIndex > nodes_.size() - 1) {
        if (nodes_[index].msencond > nodes_[leftIndex].msencond) {
            std::swap(nodes_[index], nodes_[leftIndex]);
            nextIndex = leftIndex;
        }
    } else {
        if (nodes_[leftIndex].msencond <= nodes_[rightIndex].msencond) {
            if (nodes_[index].msencond > nodes_[leftIndex].msencond) {
                std::swap(nodes_[index], nodes_[leftIndex]);
                nextIndex = leftIndex;
            }
        } else {
            if (nodes_[index].msencond > nodes_[rightIndex].msencond) {
                std::swap(nodes_[index], nodes_[rightIndex]);
                nextIndex = rightIndex;
            }
        }
    }

    DownBalance(nextIndex);
}