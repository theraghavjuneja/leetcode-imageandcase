### Cycle Detection in Directed Graph
- This will discuss the BFS method(using Kahn algorithm) for detecting the cycle in directed graph
```cpp
#include <iostream>
#include <vector>
using namespace std;
// bfs kahn algo for cycle
bool searhCycle(vector<vector<int>>&adjList)
{
    // given an adjList, check for cycle 
    vector<int>inDegree(adjList.size(),0); //O(N)
    for(int i=0;i<adjList.size();i++)
    {
        for(int element:adjList[i]){
            inDegree[element]++;
        }
    }
    // push 0 indegree to queue
    queue<int>q;
    for(int i=0;i<inDegree.size();i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    vector<int>answer;
    while(!q.empty()){
        int fr=q.front();
        answer.push_back(fr);
        q.pop();
        for(int element:adjList[fr]){
            inDegree[element]--;
            if(inDegree[element]==0)
            {
                q.push(element);
            }
        }
    }
    if(answer.size()<adjList.size()){
        return true;
        
            }
            return false;
}
```