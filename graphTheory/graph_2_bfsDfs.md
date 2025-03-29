# Graph Traversal Essentials

## Understanding Graph Traversal
 A **binary tree** is also a special type of graph.

Let's first visualize an example graph:

```
    1 ---- 2       5 ---- 6       8 ---- 9       10
    |      |       |                (isolated)
    |      |       |
    3 ---- 4       7
```

This graph consists of multiple **disconnected components**, meaning some nodes are not reachable from others.

## What Do We Need for Graph Traversal?
When traversing a graph using **Breadth-First Search (BFS)** or **Depth-First Search (DFS)**, we must ensure that we do not revisit nodes unnecessarily. To achieve this, we use a **visited** structure.

### Why Do We Need a Visited Structure?
1. **Avoid Revisiting Nodes**: Without tracking visited nodes, the traversal may enter infinite loops or revisit the same nodes, leading to incorrect results.
2. **Ensuring Correct Order**: In BFS, when a node (e.g., `1`) is connected to multiple nodes (`2` and `3`), we must ensure we do not visit the same node twice. Example how we would know whether 1->2,3 which of 2,3 has already been visited.
3. **Handling Disconnected Components**: If a graph has multiple disconnected components, a traversal from one node will not reach all nodes. We must manually check for unvisited nodes due to which bfs/dfs 
### Example Execution
For the given graph:
- We start BFS/DFS from node `1`, marking `1, 2, 3, 4` as visited.
- Since the graph is disconnected, the traversal does not reach `5`. Thus, we explicitly check and start another BFS/DFS from `5`, then `8`, and finally `10`.
- The calls for BFS/DFS occur at **1 → 5 → 8 → 10**, ensuring every component is explored.

## Implementing the Visited Structure
We can store visited nodes using:
1. **Vector (for a known number of nodes)**:
   ```cpp
   vector<bool> visited(nodes, false);
   ```
2. **Unordered Map (for unknown or sparse graphs)**:
   ```cpp
   unordered_map<int, bool> visited;
   ```
Both methods help track whether a node has been visited during traversal.

---
## So now I will start with Breadth First Search
```code
        1       lvl 0
       / \
      2   6     lvl 1
     / \  | \
    3   4 7  9  lvl 2

```
### A BFS essentialy means we should traverse level by level. Remember, for this in tree we used a queue(FIFO remember? so that's BFS here too)
1 2 6 3 4 7 9
- essentialy i will push 1 into queue, I will pop queue front i.e. 1 push the neighbors 2,6
- again i will pop (this time 2) push neighbors 3,4

- a graph essentially is a tree, just instead of 2 I have n children (or neighbors what we call here)

```cpp
void bfs(int node,queue<int>&q,vector<vector<int>>&adj,vector<bool>&visited,vector<int>&answer){
        visited[node]=true;
        q.push(node);
        while(!q.empty()){
            int top=q.front();
            q.pop();
            answer.push_back(top);
            for(int neighbor:adj[top]){
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    q.push(neighbor);
                }
            }
        }
    }
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // adj = [[2,3,1], [0], [0,4], [0], [2]]
        // meaning 0 connected to 2,3,1 given adjList
        // 1 to 0 and so on
        vector<bool>visited(adj.size(),false); // vis node
        vector<int>answer;
        queue<int>q;
        bfs(0,q,adj,visited,answer); //question states to do bfs only at node 0,

        // if disconnected do this
        // for(int i=0;i<adj.size();i++){
        //     if(!visited[i]){
        //         // if node is not visited try to visit all adj nodes to it
        //         bfs(i,q,adj,visited,answer);
                
        //     }
        // }
        return answer;
        
        
    }
```

- remember visited is used no matter all nodes are connected or one component is disconnected or not

# Now I will do DFs traversal of a graph,
- In dfs we go to any of neighboring nodes and will continue going to neighbor(for instance, we continue going to left nbr in a tree)
```code
    1
   / \
  2   3—4
 / \  |  |
5   6 7—8

```
### We will 
- 1->2->5 Now return to 2
- Now at 2, one nbr 5 has been processed so we go to 6 and so on..
### calls may look like
```code
DFS(1)
 ├── DFS(2)
 │   ├── DFS(5)
 │   ├── (Backtrack)
 │   ├── DFS(6)
 │   ├── (Backtrack)
 │   ├── (Return to 1)
 ├── DFS(3)
 │   ├── DFS(7)
 │   ├── DFS(8)
 │   ├── DFS(4)
 │   ├── (Backtrack to 1)
 ├── (End)

```
## Since, we are moving in a particular direction, and ddoing stuff like backtracking, we might use  recursion etc
```cpp
#include <iostream>
#include <vector>
using namespace std;
void dfs(int node,vector<bool>&visited,vector<vector<int>>&adj,vector<int>&answer){
        visited[node]=true;
        answer.push_back(node);
        for(int nbr:adj[node]){
            if(!visited[nbr]){
                dfs(nbr,visited,adj,answer);
            }
        }
    }
    vector<int> DFS(vector<vector<int>>& adj) {
        vector<bool>visited(adj.size(),false);
        vector<int>answer;
        dfs(0,visited,adj,answer); 
        '''
        The question only stated that I need to do dfs of all nodes connected to 0 and not the other nodes.
        If there were other nodes, I would have to do the similar procedure
        '''
        return answer;
    }
``` 