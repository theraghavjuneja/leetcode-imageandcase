## TOPOlOGICal SORT
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