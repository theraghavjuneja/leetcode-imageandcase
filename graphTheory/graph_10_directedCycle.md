## Cycle Detection in Directed Graph
- So , I can easily detect cycles in directed graph using the methodology of Depth First Seach
## The concept is if Node is visited as well as dfsVisited, then there is a cycle present
## Given Graph Representation
Consider a graph like this
There is also an edge from 8 to 

```
    1 → 2 → 3 → 7 → 5 → 6
            ↓   ↑
            4 → 5

        8 → 9 → 10
        ↑       ↓
        |_______|
```

Calls goes on like this
```
DFS(1)
│
└── DFS(2)
    │
    ├── DFS(3)
    │   │
    │   ├── DFS(4)
    │   │   └── DFS(5)
    │   │       └── DFS(6) ← Backtrack
    │   │
    │   └── DFS(7) ← Backtrack
    │
    └── Backtrack

DFS(8)
│
├── DFS(9)
│   └── DFS(10)
│       └── Back to 8 (Cycle Detected)
│
└── Backtrack
```

## Esentiialy, I found I need to keep track of dfsVisited and visited . If a node is visited as well as dfsVisited= cycle is present
```cpp
#include <iostream>
#include <vector>
using namespace std;
bool dfs(int node,vector<bool>&visited,vector<bool>&dfsVisited,vector<vector<int>>&adjList){
    visited[node]=true;
    dfsVisited[node]=true;
    for(int neighbor:adjList[node]){
        if(!visited[neighbor]){
            if(dfs(neighbor,visited,dfsVisited,adjList)){
                return true;
            }
        }
        else if(dfsVisited[neighbor]){
            // meaning visited + dfs visited
            return true;
        }
    }
    dfsVisited[node]=false; //Mark current node as false while backtracking
    return false;
}
bool cycleDetect(vector<vector<int>>&adjList){
    vector<bool>visited(adjList.size(),false);
    vector<bool>dfsVisited(adjList.size(),false);
    int n=adjList.size();
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfs(i,visited,dfsVisited,adjList)){
                return true;
            }
        }

    }
    return false;
}
```