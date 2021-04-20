using namespace std;
#include <iostream>
#include <fstream>
#include <string.h>
#include "Dijkshtras.h"

void shortest_path(List *list,int u, int v)
{
    
    
    
}
void read_graph(char* fname,char* type)
{
    Node *node;
    List *list,*temp;
    int m,n,e,u,v,w;
    ifstream fp(fname);
    if (!fp)// if the read file does not exist then
    {
        cout<<"Error: cannot open file for reading"<<endl;
    }
    fp>>n>>m;
    node=new Node[n];
    list=new List[n];
    for(int i=0;i<n;i++)
    {
        node[i].p=-1;
        node[i].d=infinity;
        node[i].v=i+1;
        node[i].dis=-1;
        node[i].ex=-1;
        list[i].next=NULL;
    }
    for(int i=0;i<m;i++)
    {
        fp>>e>>u>>v>>w;
        List* node=new List;
        temp=&list[u-1];
        while(temp->next!=NULL)
        {
            temp=temp->next;   
        }
        temp->next=node;
        node->w=w;
        node->v=v;
        node->next=NULL;
        if(strcmp(type,"undirected")==0)
        {
            List* node=new List;
            temp=&list[v-1];
            while(temp->next!=NULL)
            {
                temp=temp->next;   
            }
            temp->next=node;
            node->w=w;
            node->v=u;
            node->next=NULL;
        }
        
    }
    /* print the graph
    for(int i=0;i<n;i++)
    {
        cout<<"\n"<<i+1<<"-->";
        if(list[i].next==NULL)
        {
            cout<<"X";
        }
        else
        {
            List *temp=list[i].next;
            while(temp!=NULL)
            {
                cout<<"|"<<temp->v<<"|"<<temp->w<<"|";
                if(temp->next!=NULL)
                    cout<<"-->";
                else
                    cout<<"X";
                temp=temp->next;
            }
        }
        
    }*/
}