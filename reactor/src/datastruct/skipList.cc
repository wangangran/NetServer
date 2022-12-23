#include <cstdlib>
#include <atomic>

template<typename Key, typename Comparator>
class SkipList {
private:
    struct Node;
};

template<typename Key, typename Comparator>
struct SkipList<Key, Comparator>::Node {
    explicit Node(Key k) : key(k) {} 
    Key const key;
private:
    std::atomic<Node*> next[1]; 
};

int main(int argc, char **argv) {
    Node t;
    return 0;
}