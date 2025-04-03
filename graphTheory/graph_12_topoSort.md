# TOPOlOGICal SORT( ONLY FOR DIRECTED ACYLIC GRAPH)
## METHOD 1 DFS & STACK (Push to stack while btrking)
#### Important Point: If no node has indegree 0, that means there is a cycle in the graph. I fthere is a cycle that means it is not possible to do the topological sort
- Okay so basically let's say I have a graph,
- TS says , linear ordering such that for every edge u-v , u appear before v in topological sort
### I forgot this (Key points)
**1** I need a stack for this traversal
**2** I need to push in stack after traversing all its neighbors or while back tracking i need to push
**3** Normal topological sort is a DFS algo
**4** for u-v , u should appear before v, thus in stack too upar m u hoga nichme mein v, that's why we initially go to neighbors and push them to stack
```
5->0<-4
|     |
2->3->1
```
## Assume above 5 goes to 2 and 4 goes to 1.
- It's one topolocial sort can be
- 5 4 2 3 1 0
- for every edge example 5-2 is an edge and 5 is before 2, 4->1 is an edge and 4 is before 1

### Approach , I will take a stack
```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void dfs(int node, stack<int>&s, vector<vector<int>>&adjList,vector<bool>&visited){
    visited[node]=true;
    // jo node aati hai sabse phle uske neighbors pr jaao and unhe stack m put kro, remember since u->v mein ts m u pehle so u should be somewhere above v on stack
    for(int neighbor:adjList[node]){
        if(!visited[neighbor]){
            dfs(neighbor,s,adjList,visited);
        }
    }
    // push here
    s.push(node);
}
vector<int>topologicalSort(vector<vector<int>>&adjList){
    vector<bool>visited(adjList.size(),false);
    stack<int>stk;
    for(int i=0;i<adjList.size();i++){
        if(!visited[i]){
            dfs(i,stk,adjList,visited);
        }
    }
    vector<int>vec;
    while (!stk.empty()) {
        vec.push_back(stk.top());
        stk.pop();
    }
    return vec;

}
```

## APPROACH -2 KAHN'S ALGORITHM OR BFS
- Kahn's algorithm is a topological sorting algo based on BFs(Breadth First Search)
- Also used for detecting the cycle as if graph contains a cycle, topological sort will fail to process all nodes

### Concept Involved
- **Indegree** : In a directed graph, for a node number of nodes pointing to the node means the indegree
- **OutDegree**: No of nodes coming out of a node is the outdegree

### Intituion:
- Okay, so what we saw is in simple dfs method or simple Topological sort the ordering was 5 4 2 3 1 0 (last ques)
- what is clear here ? 0,1 are nodes with indegree 2, 2,3 are nodes with indegree 1 and 5,4 have indegree 0. from here we get the intution of  indegree thing

### So let's consider prev graph only
- Initial indegrees [2,2,1,1,0,0] 
- node 0 indegree 2, node 1 indegree 2 and so on...
- Push nodes with 0 indegree i.e.5 and 6 into queue
- process neighbors, and decrease their indegree. So indegree node 2 and 0 becomes 0
- similarly push 0 & 2 process their neighbors and so on.
```
5->0<-4
|     |
2->3->1
```
```cpp
#include<iostream>
#include<vector>
#include <queue>
using namespace std;
vector<int> kahnTopologicalSort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> indegree(n, 0);
    vector<int> topoOrder;
    // visiited not needed
    // Compute indegree of each node
    for (int i = 0; i < n; i++) {
        for (int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }

    queue<int> q;

    // Add all nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        // Reduce indegree of neighbors
        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            // visited not needed 
            // Reason: 0 indegree initial nodes pushed aab wo nodes dobara nahi aayegi as kisi ka neighbor so visited not needed
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If the number of nodes in topoOrder is less than total nodes, a cycle exists
    // Reason: due to cycle, at a point there will be no nodes with 0 indegree, so processing will stop
    if (topoOrder.size() < n) {
        cout << "Cycle detected! Topological sorting is not possible.\n";
        return {};
    }

    return topoOrder;
}
}


```
