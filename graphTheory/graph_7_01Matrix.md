# 542 01 MATRIX
## Given a binary matrix, I need to return distance of nearest 0 for each cell

### Intuition
- I have got a matrix containing only 0's and only 1's . Now whenever element is 0 , distance from nearest 0 is 0.
- Whenever element is 1, here I need to find distance from nearest 0
- so essentially, I should declare a matrix answer with all elements equal to zero. In original matrix, wheenever element is 1, the corresponding element of answer matrix should be changed . That's it i need to do
#### **BFS Or DP**
- I need to essentialy find shortest distance from every cell to the nearest 0, treating all 0s as starting points and expanding outwards in layers is ideal. **BFS naturally finds the shortest path in an unweighted grid.**
- **Efficient Exploration**: BFS ensures that each cell is processed in order of increasing distance, so once we visit a cell, we are guaranteed to have found the shortest path to it.
- also, always say there are multiple 0's (all of them will have distance=0). Now the 0 which was nearest essentially will reach the nearest one faster as initially all nodes having distance 0 will be passed
- Example
```code
0 0 0
0 1 0
1 1 1
```
- Here, for one at extreme right bottom, the zero at position mat[1][2] will reach the fastest. this is what bfs provides us. it automatically keep on maintaining this kind of shortest distance without explicityly tracking numerous number of conditions (propery of queue )
```cpp
class Solution {
public:
    vector<vector<int>>solve(
        vector<vector<int>>& mat,
        int rows,
        int cols,
        vector<vector<bool>>&visited,
        queue<pair<int,pair<int,int>>>&q
        ){
            vector<vector<int>>answer(rows,vector<int>(cols,0));
            vector<pair<int, int>> directions = 
            {
                {0, 1}, {1, 0}, {0, -1}, {-1, 0}
            };

            while(!q.empty()){
                auto frontEntity = q.front();
                q.pop();

                int dist = frontEntity.first;
                int x = frontEntity.second.first;
                int y = frontEntity.second.second;

                for (auto dir : directions) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    // Check if within bounds and not visited
                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && !visited[newX][newY])               {
                        if(mat[newX][newY]==1)
                        {
                            visited[newX][newY] = true;
                            q.push({dist + 1, {newX, newY}});
                            answer[newX][newY]=dist+1;
                            mat[newX][newY]=0;
                        }
                        
                    }
                }

            }
            return answer;
        }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,pair<int,int>>>q;
        int rows=mat.size(),cols=mat[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false)); //remember inside bracket we dont give name of vector

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j]==0){
                    q.push(make_pair(0,make_pair(i,j)));
                    visited[i][j]=true;
                }
            }
        }
        return solve(mat,rows,cols,visited,q);


    }
};
```