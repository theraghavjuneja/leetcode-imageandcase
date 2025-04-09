## 785 Is Graph BiPartite?
#### Question says, We need to check whether a graph is bipartite. What is a bipartite graph? so, basic definition is related to disjoint set which no one understands. A bipartite is one - a graph is bipartite if it does not have odd-length cycles. in short, a graph with absence of odd length cycles. 
#### In practise, we check bipartite using following thing. Say i give a color to node 1. then its neighbors should have diff color for being a bipartite. so how do we really check? do traversal and then keep on giving color. if we encounter a neighbor with same color-> not bipartite

```cpp
class Solution {
public:
    bool bfs(int node, vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& colors) {
        queue<pair<int, int>> q; // 2nd int -> 0 or 1 for color
        q.push({node, 0});
        colors[node] = 0;
        visited[node] = true;
        
        while (!q.empty()) {
            auto [front, color] = q.front();
            q.pop();
            for (int neighbor : adjList[front]) {
                if (!visited[neighbor]) {
                    q.push({neighbor, !color});
                    colors[neighbor] = !color;
                    visited[neighbor] = true;
                } else {
                    
                    if (colors[neighbor] == colors[front]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                if (!bfs(i, graph, visited, colors)) {
                    return false;
                }
            }
        }
        return true;
    }
};
```