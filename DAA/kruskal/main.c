struct Edge
{
    int src;
    int dest;
    int wt;
};

int find(int parent[],int i){
    if (parent[i] == i) return i;
    
    return find(parent, parent[i]);
}

void unionSet(int parent[],int u,int v){
    parent[u] = v;
}

void swap(struct Edge *a, struct Edge *b) {
    struct Edge temp = *a;
    *a = *b;
    *b = temp;
}

void sortEdges(struct Edge edges[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (edges[j].wt > edges[j + 1].wt) {
                swap(&edges[j], &edges[j + 1]);
            }
        }
    }
}


void printEdges(struct Edge edges[], int n) {
    printf("Edges:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -- %d == %d\n", edges[i].src, edges[i].dest, edges[i].wt);
    }
}


void kruskal(int V,int E,struct Edge edges[]){
    int parent[V];


    for (int i = 0; i < V; i++) 
        parent[i] = i;
    
    int edge = 0;
    struct Edge mst[V-1];

    sortEdges(edges, E);

    for (int i = 0; i < V; i++)
    {
        int u = edges[i].dest;
        int v = edges[i].src;

        int uComp = find(parent,u);
        int vComp = find(parent,v);

        if (uComp != vComp)
        {
            mst[edge] = edges[i];
            unionSet(parent,uComp,vComp);
            edge++;
        }
    }
    
    printEdges(mst,V-1);
}




void main(){

    int V = 3;
    int E = 3;

    struct Edge graph[] = {
        {0, 1, 2},
        {1, 2, 4},
        {0, 2, 3}
    };

    kruskal(V,E,graph);
}