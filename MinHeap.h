
#ifndef Heap_h
#define Heap_h
//using std::string;
class MinHeap {
    
private:
    
    struct MinHeapNode {
        int vertex;
        double key;
    };
    
    int size;
    int N;
    struct MinHeapNode * heap;
    
    void swim(int k);
    void sink(int k);
    
public:
    
    MinHeap(int size);
    
    bool insert(int vertex, double key, int flag);
    bool empty();
    int getMin();
    int removeMin(int flag);
    void decreaseKey(int vertex, double newKey, int flag);
};

#endif
