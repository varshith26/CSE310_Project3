#define infinity 99999
struct Node
{
    int v,p,d,dis,ex;
};

struct List
{
    int v,w;
    List* next;
};

typedef struct Node Node;
typedef struct List List;
void shortest_path(List*,int,int);
void read_graph(char*,char*);