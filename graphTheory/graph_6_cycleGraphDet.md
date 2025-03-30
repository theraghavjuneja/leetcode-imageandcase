## Undirected Graph Cycle Detection
- in this question I will try to find graph has cycle or not
- so ofcourse that can be done with bfs & dfs se i will try it now

## **using BFS**
- M1 : No of visited node>=2 in any adjList
- M2: A cycle is detected if I visit a node that is already visited and it is not the **parent** of the current node.
```cpp
#include <vector>
#include <queue>
using namespace std;

bool bfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    queue<int> q;
    q.push(node);
    
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        int count = 0;
        
        for (int elem : adj[top]) {  
            // if(elem==top) meaning self-loop so return true
            if (!visited[elem]) {
                q.push(elem);
                visited[elem] = true;
            } else {
                count++;
            }
        }
        
        if (count >= 2) return true;  // Cycle detected
    }
    return false;
}

bool isCycle(vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    
    for (int i = 0; i < adj.size(); i++) {
        if (!visited[i]) {
            if (bfs(i, adj, visited)) {
                return true;
            }
        }
    }
    return false;
}

```

## Idk no one taught this method but for me this method passed all test casses in any coding editor
- so acc to me why this works?
- when we have >=2 visited nodes as neighbors. That means there is another way to reach these 2 except current node. so these 4 forms a cycle always

## Method -2 
- here I will try to use a parent node method
```cpp
#include <iostream>
#include <vector>
#include <queue>  // Include queue for BFS
using namespace std;

bool bfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& parent) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    parent[node] = -1;   // I ALWAYS FORGOT THIS CONDITION

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (int elem : adj[top]) {
            if (!visited[elem]) {
                visited[elem] = true;
                q.push(elem);
                parent[elem] = top; 
            } 
            else if (parent[top] != elem) {  
                return true;
            }
        }
    }
    return false;
}

bool isCycle(vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    vector<int> parent(adj.size(), -1);

    for (int i = 0; i < adj.size(); i++) {
        if (!visited[i]) {
            if (bfs(i, adj, visited, parent)) {
                return true;
            }
        }
    }
    return false;
}


int main() {
    int n, m;
    cin >> n >> m; 
    vector<vector<int>> adj(n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    if (isCycle(adj)) {
        cout << "Cycle detected\n";
    } else {
        cout << "No cycle\n";
    }

    return 0;
}


```
# THE code thought process is same
# if a neighbor is already visited and it's not parent 
## **using DFS**
- Now i will try doing the undirected graph cycle Detection using Depth First Search Method.
```cpp
bool dfs(int node,int parent,vector<bool>&visited,vector<vector<int>>&adj){
        visited[node]=true;
        for(int neighbor:adj[node]){
            if(!visited[neighbor]){
                if(dfs(neighbor,node,visited,adj)){
                    return true;
                }
            }
            else{
                // if the node is not the parent
                if(neighbor!=parent){
                    // i.e. visited but not parent
                    return true;
                }
            }
        }
        return false;
        
    }
    bool isCycle(vector<vector<int>>& adj) {
        vector<bool>visited(adj.size(),false);
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                if(dfs(i,-1,visited,adj)){
                    return true;
                }
            }
        }
        return false;
    }
```