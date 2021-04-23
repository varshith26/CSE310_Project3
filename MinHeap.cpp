

#include "MinHeap.h"

#include <iostream>
using namespace std;
#include <set>
#include <string>
using std::set;
using std::cout;
using std::endl;
//using std::string;


MinHeap::MinHeap(int size) {
    
    this->size = size;
    heap = new struct MinHeapNode[size + 1];
    this->N = 1;

}

void MinHeap::swim(int k){
    
    while( k>1 && heap[k/2].key > heap[k].key ) {
        struct MinHeapNode temp = heap[k/2];
        heap[k/2] = heap[k];
        heap[k] = temp;
        
        k = k/2;
    }
}

void MinHeap::sink(int k){
    
    while( 2*k < N ){
        int j = 2*k;
        if (j < N-1 && heap[j].key > heap[j+1].key)
            j++;
        if( !(heap[k].key > heap[j].key) ) {
            break;
        }
    
        struct MinHeapNode temp = heap[j];
        heap[j] = heap[k];
        heap[k] = temp;
        
        k = j;
    }
}

bool MinHeap::insert(int vertex, double key,int flag){
    if( N==size+1){
        return false;
    }
    if(flag)
        printf("Insert vertex %d, key=%12.4lf\n", vertex, key);
    
    heap[N].key = key;
    heap[N].vertex = vertex;
    N++;
    
    swim(N-1);
    return true;
}

bool MinHeap::empty(){
    return N==1;
}

int MinHeap::getMin(){
    return heap[N-1].vertex;
}

int MinHeap::removeMin(int flag){
    
    int min = heap[1].vertex;
    double minKey = heap[1].key;
    heap[1] = heap[N-1];
    N--;
    sink(1);
    
    if(flag)
        printf("Delete vertex %d, key=%12.4lf\n", min, minKey);
    
    return min;
}

void MinHeap::decreaseKey(int vertex, double newKey, int flag){
    for( int i=1; i<N; i++ ) {
        if( heap[i].vertex == vertex ){
            double oldKey = heap[i].key;
            heap[i].key = newKey;
            swim(i);
            if(flag)
                printf("Decrease key of vertex %d, from %12.4f to %12.4f\n", vertex, oldKey, newKey);
            return;
        }
    }
}
