
#include <iostream>
#include <fstream>
using namespace std;
#include <set>
#include <string>
using std::set;
using std::cout;
using std::endl;
//using std::string;

#include "Graph.h"
#include "util.h"


// the method to read the graph from the file
Graph * readGraphFromFile(string filename, bool directed) {
    // the graph to return
    Graph * graph = nullptr;
    
    ifstream input(filename);
    if( !input ) {
        // show message cannot read file
        cout << "Cannot open input graph file " << filename << "!" << endl;
        return nullptr;
    }
    
    // read the number of vertices and edge
    int n,m;
    input >> n >> m;
    
    // create a graph
    graph = new Graph(n,directed);
    
    // read the next m lines
    for( int i=0; i<m; i++ ) {
        int id, u, v;
        double weight;
        
        input >> id >> u >> v >> weight;
        graph->addGraphEdge(id, u, v, weight);
    }
    
    // close the file
    input.close();
    
    return graph;
}

int main(int argc, const char * argv[]) {
    
/*  
    Graph g(8, true);
    g.addGraphEdge(1, 1, 2, 10);
    g.addGraphEdge(1, 1, 4, 5);
    g.addGraphEdge(1, 2, 4, 2);
    g.addGraphEdge(1, 2, 3, 1);
    g.addGraphEdge(1, 4, 3, 9);
    g.addGraphEdge(1, 4, 2, 3);
    g.addGraphEdge(1, 4, 5, 2);
    g.addGraphEdge(1, 5, 3, 6);
    g.addGraphEdge(1, 5, 1, 7);
    g.addGraphEdge(1, 6, 3, 7);
    g.addGraphEdge(1, 6, 7, 5);
    g.addGraphEdge(1, 7, 8, 3);
    g.addGraphEdge(1, 8, 6, 1);
*/

    
    // make sure the number of arguments are 3
    if( argc!=3 ) {
        // show usage
        cout << "Usage: " << argv[0] << " <graph_file> <directed/undirected>" << endl;
        return 1;
    }
    
    // create a graph
    Graph * graph = readGraphFromFile(argv[1], string(argv[2]) == "directed");
    if( graph == nullptr )
        return 2;
    
    // the command to be read
    string command;
    //cin >> command;
    int source, destination, flag;
    int src,dest;
    command=nextCommand(&src, &dest, &flag);
    source=src;
    destination=dest;
    //cout<<command;
    while( command != "stop" ) {
        
        // if command is to find
        if( command == "find" ) {
            
            // read source destination and flag
            source=src;
            destination=dest;
            //cin >> source >> destination >> flag;
            cout<<"Query: "<<command<<" "<<source<<" "<<destination<<" "<<flag<<endl;
            // if not s valid query
            if( (source<1 || source>graph->getNumVertices()) || 
               (destination==source) || !(flag == 0 || flag==1) ) {
                cout << "Error: invalid find query\n";
            } else {
                // call find path and store this find path
                graph->SSSP(source,destination,flag,command);
            }
            
        } // else if command is to write path
        else if( command == "write" ){
            // read path
            //cin>>str;
            // read s and d
            int s=src,d=dest;
            //cin>>s>>d;
            cout<<"Query: "<<command<<" path "<<s<<" "<<d<<endl;
            if( (s<1 || s>graph->getNumVertices()) || 
                (d==s) ) {
                cout << "Error: no path computation done\n";
            }
            else if((s!=source) ||
                    (d<1 || d>graph->getNumVertices()) || 
                    (d==s) ) {
                cout << "Error: invalid source destination pair\n";
            } else {

                graph->SSSP(s,d,0,command);
                // call find path and store this find path
            }
        }
        // else this is an invalid command if this is not stop
        
        // read the command again
        //cin>>command;
        command=nextCommand(&src, &dest, &flag);
    }
    cout<<"Query: stop";
    return 0;
}
