## 1020 Number of Enclaves Leetcode
### Problem Statement Understanding:
- Essentially, I am given a binary matrix called grid, which can have only two things **0** and **1**. 
## Given -> 
- **0** means **sea**
- **1** means **land**
### How is a move defined?
- Let's say i am a person who is moving on this matrix. Ofcourse I can move only on land cells inside matrix. So essentially, one move is I can move from from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
- Now say I am on a land cell, which is surrounded by all water cells. From that land cell, I can't move off the grid in any condition(This is just one case). We need to return no of land cells for which I can't go off the grid.
- Remember, I can move L,R,T,B

### Why not a DP Problem? How to get Graph Intution?
- Generally, (in interview or lc level), dp problems have 2 movements right, or bottom (or any two). Generally, they are about finding shortest path from top to bottom when addition of each value of matrix increases the path's cost
- dp is generally about optimal substructure, like previous problem depend on current or vice versa.
- Here, the best will be to start from 1's on boundary, push them to queue and check whether which all 1s are indirectly connected to boundary
- Any land cell that is not reached from the boundary must be completely enclosed and should be counted.(From those, I cant walk off the boundary of grid).


```cpp
class Solution {
public:
    int answer(vector<vector<int>>&matrix,vector<vector<bool>>&visited,int n,int m)
    {
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            if (matrix[0][i] == 1) {
                visited[0][i]=true;
                q.push({0, i});
            }
        }

        for (int i = 0; i < m; ++i) {
            if (matrix[n-1][i] == 1) {
                visited[n-1][i]=true;
                q.push({n-1, i});
            }
        }

    
        for (int i = 1; i < n - 1; ++i) {
            if (matrix[i][0] == 1) {
                visited[i][0]=true;
                q.push({i, 0});
            }
        }

        
        for (int i = 1; i < n - 1; ++i) {
            if (matrix[i][m-1] == 1) {
                visited[i][m-1]=true;
                q.push({i, m-1});
            }
        }

        while(!q.empty())
        {
            pair<int,int>frontNode=q.front();
            q.pop();
            int xCoordinate=frontNode.first;
            int yCoordinate=frontNode.second;
            int directions[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
            for(int d=0;d<4;d++)
            {
                int new_x=xCoordinate+directions[d][0];
                int new_y=yCoordinate+directions[d][1];
                if(new_x>=0 && new_x<n &&new_y>=0 &&new_y<m)
                {
                    if(matrix[new_x][new_y]==1 &&!visited[new_x][new_y])
                    {
                        visited[new_x][new_y]=true;
                        q.push({new_x,new_y});
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==1 &&visited[i][j]==false)
                {
                    count++;
                }
            }
        }
        return count;

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        return answer(grid,visited,n,m);

    }
};
```
