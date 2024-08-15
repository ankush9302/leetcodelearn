// brute force C++ program to find articulation points in an undirected graph
// Time Complexity: O(V*(V+E)) for a graph represented using an adjacency list.
// Auxiliary Space: O(V+E)

#include <bits/stdc++.h>
using namespace std;

// A recursive function to traverse the graph without
// considering the ith vertex and its associated edges
void dfs(vector<int> adj[], int V, vector<int> &vis,int i, int curr)
{
    vis[curr] = 1;
    for(auto it:adj[curr]){
        if(it!=i and !vis[it]){
            dfs(adj, V, vis, i, it);
        }
    }
}

// Function to find Articulation Points in the graph
void AP(vector<int> adj[], int V)
{
   //will try removing each vertex and check for components each time
   for (int i = 1; i <=V;i++)
   {
      //i represent that vertex which is removed
      vector<int> vis(V+1, 0);
      int component = 0;
      for (int j = 1; j <= V; j++){
        if(i!=j){
            if(!vis[j]){
                dfs(adj, V, vis, i, j);
                component++;
            }
        }
        
      }
    //   cout << "for i=" << i << " visited array looks as follows" << endl;
    //   for(auto it:vis){
    //       cout << it << " ";
    //   }
    //   cout << endl;
    //   if(i==4)
    //   cout << component << endl;
      if (component > 1)
      {
          cout << "this is one of the articulation point= " << i << endl;
            
        }
   }
}

// Utility function to add an edge
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Driver Code
int main()
{
    // Create graphs given in above diagrams
    cout << "Articulation points in the first graph \n";
    int V = 5;
    vector<int> adj1[V + 1];
    addEdge(adj1, 1, 2);
    addEdge(adj1, 2, 3);
    addEdge(adj1, 1, 3);
    addEdge(adj1, 3, 4);
    addEdge(adj1, 4, 5);
    AP(adj1, V);

    cout << "\nArticulation points in second graph \n";
    V = 4;
    vector<int> adj2[V+1];
    addEdge(adj2, 0, 1);
    addEdge(adj2, 1, 2);
    addEdge(adj2, 2, 3);
    AP(adj2, V);

    cout << "\nArticulation points in third graph \n";
    V = 7;
    vector<int> adj3[V+1];
    addEdge(adj3, 0, 1);
    addEdge(adj3, 1, 2);
    addEdge(adj3, 2, 0);
    addEdge(adj3, 1, 3);
    addEdge(adj3, 1, 4);
    addEdge(adj3, 1, 6);
    addEdge(adj3, 3, 5);
    addEdge(adj3, 4, 5);
    AP(adj3, V);

    return 0;
}
