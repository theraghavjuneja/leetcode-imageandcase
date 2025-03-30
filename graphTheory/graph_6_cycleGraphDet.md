## Undirected Graph Cycle Detection
- in this question I will try to find graph has cycle or not
- so ofcourse that can be done with bfs & dfs se i will try it now

## **using BFS**
- M1 : No of visited node>=2 in any adjList
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