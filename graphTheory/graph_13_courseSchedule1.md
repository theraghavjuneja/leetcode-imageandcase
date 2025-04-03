### Course Schedule 1 problem
## Problem Statement:
- I need to take a total of courses=numCourses
- an array is given called preq where preq[i]=[a,b] i.e. b must be taken before a .
- True of all courses can be finished else False

### Intiution
- How did I come to know it's a graph question?
- Recall the definition of ts, it says for every edge u-v , u before v right?
- this gave me the idea of using Topological Sort
### Coming back to the question

### Example 1,
- Given numCourses=2, prereq=[[1,0]]
### What I can understand is tot take course 1, I should have finished course 0
- Graph will look like 0->1 , I can easily traverse graph no mutual dependency so possible
### Example 2
- Given num Courses=2, prereq=[[1,0],[0,1]]
### 0->1 and 1->0
```
0->1
1->0
```
### I can't do topological sort here, or I can say here is a cycle so it't not possible
### This is what our question is saying. Now next part I should code the problem out 

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adjList;  
        vector<int>indegree(numCourses,0); //initial indegree 0
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adjList[v].push_back(u); // to take u i should have taken v
            indegree[u]++;
        }
        // now graph is already made
        // Remember visited is not required in topological Sort
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>tSort;
        while(!q.empty()){
            int node=q.front();
            tSort.push_back(node);
            q.pop();
            for(int neighbor:adjList[node]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }
        if(tSort.size()<numCourses) return false; // I cant finish all courses, there is a cyclic dependency
        return true;
        
        

    }
};

```