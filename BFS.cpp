#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int v;
    // This is to make the adjacency list with which we will represenet the graph
    vector<list<int>> adj_list;
    public:
    //This is to intialize the number of nodes in the graph(This is the parameter)
    Graph(int v);
    // This is to add edges to the graph(Parameters denote which nodes are connected)
    void addEdge(int v,int w);
    // This is for the actual BFS traversal(parameter is the node which we want to start at)
    void BFS(int s);

};

Graph::Graph(int v)
{
    this->v=v;
    // The resize function is used to fix the size of the vector
    adj_list.resize(v);
}
 void Graph::addEdge(int v,int w)
{
    adj_list[v].push_back(w);
}

void Graph::BFS(int s)
{
    vector<bool>visited;
    visited.resize(v,false);
    visited[s]=true;
    list<int>q;
    q.push_back(s);
    while (!q.empty())
    {
            s=q.front();
            cout<<s;
            q.pop_front();
        
        for(auto adjacent:adj_list[s])
        {
            if(!visited[adjacent])
            {
                visited[adjacent]=true;
            q.push_back(adjacent);
            }
            
        }
        
    }
    
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    return 0;
}