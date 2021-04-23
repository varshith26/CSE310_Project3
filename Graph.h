

#ifndef Graph_h
#define Graph_h

#include <iostream>
#include <string>
#include "MinHeap.h"
#include <set>
using std::set;
using std::cout;
using std::endl;
using std::string;
// creating a graph

class Graph
{

private:
    
    struct AdjacentListNode
    {
        int id;
        int destination;
        double weight;
        struct AdjacentListNode* next;
    };

    // adjacency lists
    struct AdjacencyList
    {
        int vertex;
        struct AdjacentListNode *head;
    };


    int numVertices;
    bool directed;
    struct AdjacencyList* arr;
    int *pi,*discovery;
    double *key;
    int *ex;
    int count;
    AdjacentListNode* newAdjListNode(int id, int destination, double weight);
    MinHeap *heap;

public:
        
    Graph(int vertex, bool directed);

    void addGraphEdge(int id, int source, int destination, double);
    
    bool edgeExists(int source, int destination) ;
    
    bool containsVertex(int source);
    
    int getNumVertices();

    void SSSP(int source,int destination,int flag, string command);

    friend std::ostream &operator<<( std::ostream &output, const Graph & rhs );

};


#endif /* Graph */
