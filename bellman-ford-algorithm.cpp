#include<bits/stdc++.h>

using namespace std;

void BellmanFord(int graph[][3],int V,int E,int source)
{
    //array of distance of vertex
    int d[V];

    //initially distance of every vertex is set to infinity except the source vertex
    for(int i=0;i<V;i++)
    {
        d[i]=INT_MAX;
    }
    d[source]=0;

    /*now we perform relaxation V-1 times on every edge*/
    for(int i=0;i<V-1;i++)
    {
        for(int j=0;j<E;j++)
        {
             if(d[graph[j][0]]+graph[j][2]<d[graph[j][1]])
                    d[graph[j][1]]=d[graph[j][0]]+graph[j][2];
        }
    }

    /*check if the distance changes even after V-1 iterations
      if yes then negative cycle exists*/
    for(int i=0;i<E;i++)
    {
        if(d[i]!=INT_MAX && d[graph[i][0]]+graph[i][2]<d[graph[i][1]])
            cout<<"GRAPH HAS A NEGATIVE WEIGHT CYCLE"<<endl;
    }

    /*print the distances from source vertex to all other vertices*/
    cout<<"VERTEX DISTANCE FROM SOURCE"<<endl;
    for (int i=0;i<V;i++)
        cout<<i<<"\t\t"<<d[i]<< endl;
}

int main()
{
    int V=7;  //number of vertices
    int E=10; //number of edges

    /*we form a graph matrix of Ex3
      i.e every row corresponds to an edge
      and 3 elements in an edge corresponds
      to (u,v,w) where u is the starting vertex
      v is the ending vertex and w is the weight
      of the edge*/
    int graph[][3]={
    {0,1,6},{0,2,5},
    {0,3,5},{1,4,-1},
    {3,2,-2},{2,1,-2},
    {2,4,1},{3,5,-1},
    {4,6,3},{5,6,3}
    };

    //apply bellman ford to the source vertex
    BellmanFord(graph,V,E,0);
}
