### Basics/ Theory
- I need to find **number of provinces** or **number of connected components**. So that actually means each bfs call (total bfs calls isn't it). 
- or no of dfs calls from main function only
- so practically I can just declare a count variable that's it
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
    vector<bool>visited(n,false) ;//Declare visited
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