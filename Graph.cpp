
#include "Graph.h"
#include <set>
#include<math.h>
#include<cmath>
#include <iterator>
#include <string>
using std::set;
using std::cout;
using std::endl;
//#include <limits>
//double infinity = std::numeric_limits<double>::max();

typename Graph::AdjacentListNode* Graph::newAdjListNode(int id, int destination, double weight)
{
    AdjacentListNode* tempNewNode = new AdjacentListNode;
    
    tempNewNode->destination = destination;
    tempNewNode->weight = weight;
    tempNewNode->id = id;
    tempNewNode->next = NULL;
    
    return tempNewNode;
}

Graph::Graph(int numVertices, bool directed)
{
    this->numVertices = numVertices;
    this->directed = directed;
    pi=new int[numVertices + 1];
    key=new double[numVertices + 1];
    ex=new int[numVertices+1];
    discovery=new int[numVertices+1];
    count=0;
    arr = new AdjacencyList [numVertices + 1];
    //heap=new MinHeap(numVertices);
    for (int i = 1; i <= numVertices; ++i)
        arr[i].head = NULL;
}

void Graph::addGraphEdge(int id, int source, int destination, double weight)
{
    if( !containsVertex(source) || !containsVertex(destination))
        return;
    
    AdjacentListNode* tempNewNode = newAdjListNode(id, destination, weight);
    tempNewNode->next = arr[source].head;
    arr[source].head = tempNewNode;
    
    // adding the source as the neighbor of destination because this is a undirected graph
    if( !directed ) {
        tempNewNode = newAdjListNode(id, source, weight);
        tempNewNode->next = arr[destination].head;
        arr[destination].head = tempNewNode;
    }
}

bool Graph::edgeExists(int source, int destination) {
    
    if( !containsVertex(source) || !containsVertex(destination))
        return false;
    
    AdjacentListNode * curr = arr[source].head;
    while( curr != nullptr ){
        if( curr->destination == destination )
            return true;
        curr = curr->next;
    }
    return false;
}

bool Graph::containsVertex(int source) {
    return source >=1 && source <= numVertices;
}

std::ostream &operator<<( std::ostream &output, const Graph & rhs ) {

    for( int i=1; i<=rhs.numVertices; i++ ){
        std::cout << i << ": ";
        
        typename Graph::AdjacentListNode * curr = rhs.arr[i].head;
        while( curr != nullptr ){
            std::cout << curr->destination << " ";
            curr = curr->next;
        }
        
        std::cout << std::endl;
    }

    return output;
}

int Graph::getNumVertices(){
    return numVertices;
}

// TODO: use the exact same code to find the path till a destination
// just break the while loop at the destination
void Graph::SSSP(int source, int destination,int flag, string command){
    
    int *S=new int[numVertices+1],top=-1;
    
    if(command=="find"){
        free(heap);
    //MinHeap heap(numVertices);
    heap=new MinHeap(numVertices);
    heap->insert(source, 0,flag);
    
    
    for( int i=1; i<=numVertices; i++ ) {
        pi[i] = -1;
        key[i] = 0.0;
        ex[i]=0;
        discovery[i]=0;
    }
    
    while( !heap->empty() /*&& heap.getMin()!=destination*/) {
        int u = heap->removeMin(flag);
        ex[u]=++count;
        if (u==destination)
            break;
        //cout<<u<<endl;
        //S.insert(S.begin(),u);
        
        AdjacentListNode* curr = arr[u].head;
        while( curr ) {
            int v = curr->destination;
            //cout<<v<<endl;
            //cout<<key[v]<<endl;
            //cout<<fabs(floor(key[v] - INFINITY))<<endl;
            if(ex[v]==0){
            if( fabs(key[v] - 0.0) < 0.01f ) {
                key[v] = key[u] + curr->weight;
                pi[v] = u;
                heap->insert(v, key[v],flag);
            } else if( key[v] > (key[u] + curr->weight) ) {
                key[v] = key[u] + curr->weight;
                pi[v] = u;
                heap->decreaseKey(v, key[v],flag);
                
            }
           // cout<<pi[v]<<endl;
            } 
            curr = curr->next;
        }
    }
    }
    if(command=="write")
    {
    	if(pi[destination]==-1&&heap->empty())
    		cout<<"No "<<source<<"-"<<destination<<" path exists.\n";
    	else if(pi[destination]==-1&&!heap->empty())
    	    cout<<"No "<<source<<"-"<<destination<<" path has been computed.\n";
    	else
    	{
    		S[++top]=destination;
    		int x=pi[destination];
    		while(x!=-1){
    			S[++top]=x;
    			x=pi[x];
    		}
    		//S.insert(S.begin(),x);
    		
    		if(ex[destination]!=0)
    		    cout<<"Shortest Path: <"; 
    		else
    		    cout<<"Path not known to be shortest: <";
    		for(int itr=top;itr>0;itr--)
    			cout<<S[itr]<<", ";
			cout<<S[0]<<">\n"
    		//printf("\b\b>\n");
    		printf("The path weight is:%12.4lf\n",key[destination]);
    	}	
    }
}
