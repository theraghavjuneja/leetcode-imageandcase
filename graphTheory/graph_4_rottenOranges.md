# LC 994 Rotten Oranges
### Problem Statement: Given a matrix, where
- 0 means an empty cell
- 1 means a fresh orange
- 2 means a rotten orange
### **Additional Note**: Every minute any fresh orange 4-directionally adjacent to rotten orange becomes rotten
- I need to find number of minutes until no cell has fresh orange
- also remember there may be more than one rotten orange initially (Tradittionaly, multi source thing)

### Okay, so let me consider an example
```code
Rotten Fresh Fresh
Fresh Fresh Empty
Empty Fresh Fresh

```
## After t=1(say R=rotten, F=fresh, e=empt)
```code
R R F     R R R      R R R      R R R
R F E     R R E      R R E      R R E
E F F     E F F      E R F      E R R
(t=1)     (t=2)      (t=3)      (t=4)
```
So, it took 4 seconds. 

### Now let's try to build intitution
- Say let's consider above test case only where mat[0][0] is rotten. After t=1 mat[0][1] and mat[1][0] becomes rotten.
- In short for any rotten orange, after 1 second one cell above, below, left and right will become rotten . That's what we should think about
- So what I can do is I can take rotten orange, go to its neighbors, then start from neighbor and again go to neighbor and so on till we are out of matrix(Out of bounds). Isn't it? So that makes me think of something like BFS.
### WHY NOT DP?
- Since this problem has parallel  propagation, I was unable to form a recursive relationship (as far as I thought). so for each i should go parallerly

## What should the code be like?
- i will see all rotten oranges initially, push them to q, parallerly traverse all neighbors of each rotten orange. WIll continue till q gets emtpy
- if q gets empty, I should check any fresh remains. If it remains, that's unreachable as simple as that
```cpp
class Solution {
public:
    int bfs(
        queue<pair<int,pair<int,int>>>&q,
        vector<vector<int>>&grid,
        vector<vector<bool>>&visited,
        int rows,
        int cols
        ){
            vector<vector<int>>distance={
                {1,0},
                {0,1},
                {0,-1},
                {-1,0}
            };
            int answer=0;
            while(!q.empty()){
                pair<int,pair<int,int>>top=q.front();
                q.pop();
                int time=top.first;
                answer=max(time,answer); // or answer=time would also work
                int origX=top.second.first;
                int origY=top.second.second;
                for(int i=0;i<distance.size();i++){
                    int newX=origX+distance[i][0];
                    int newY=origY+distance[i][1];
                    if(newX>=0 &&newX<rows&&newY>=0&&newY<cols){
                        if(!visited[newX][newY] &&grid[newX][newY]==1){
                            cout<<"Called"<<endl;
                            q.push({time+1,{newX,newY}});
                            grid[newX][newY]=2;
                        }
                    }
                }
            }
            return answer;
            
        }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<bool>>visited(n,vector<bool>(m,false)); //n rows each row has m elem=to false
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(0,make_pair(i,j)));
                    visited[i][j]=true;
                }
            }
        }
        int ans=bfs(q,grid,visited,n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};
```