### Basics/ Theory
- I need to find **number of provinces** or **number of connected components**. So that actually means each bfs call (total bfs calls isn't it). 
- or no of dfs calls from main function only
- so practically I can just declare a count variable that's it

## Intitution: In graph theory, we might see things like disconnected components. Each BFS call traverse each component and this is what we need to total
```cpp
#include <iostream>
#include <vector>
using namespace std;
void bfs(int node,vector<bool>&visited,vector<vector<int>>&isConnected){
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int top=q.front();
        '''
        so, i should process top neighbors now, Now neighbors are ones jiski values 1 hai
        example 
        '''
        q.pop();
        //Each node adjList is checked completely O(n) even if visited it is checeked
        for(int j=0;j<isConnected.size();j++){
            if(isConnected[top][j]==1 &&!visited[j]){
                q.push(j);
                visited[j]=true;
            }
        }
    }
}
int findCircleNum(vector<vector<int>>& isConnected){
    '''
    Given that isConnected is a 2-D Matrix(adj matrix)
    where ==0 for disconnected else connected
    '''
    int n=isConnected.size();// Represents visited size
    vector<bool>visited(n,false) ;//Declare visited O(n)
    int count=0;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bfs(i,visited,isConnected);

            count++;
        }
    }
    return count;
}
```
## Time complexity at max will be O(n)*O(n) i.e. O(n)^2 here. Remember matrix is n*n(rows*columns) each element will be checked at most once thus O(n square)