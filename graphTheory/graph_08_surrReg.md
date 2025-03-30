## 130 Surrounded Regions
### Given a matrix m*n -> contains 'X' and 'O'
### Aim- to capture regions that are surrounded
- for each cell, i can go left, right, top, bottom (Generally whenever there are 4 choices we do bfs (90%). in 2 choices we do DP etc.)

## What I need to do?
- We need to connect 0's to form a region. And a region is said to be surrounded, if any of the 0 inside the region is not connected to any 0 on the edge
- all the "O" that are not directly/indirectly connected to the "O" on boundary line will be converted to "X"
- Essentially, I can start bfs with "O"s on edges and keep track of their occurence. Except them  , all of the Os will be converted to X
- meaning, i can declare a 2d bool with all false. Now if any 'O' is directly /indirectly connected to boundary, i will change that to true.
- at end i will check all Os that have this boolean as false. will convert them to X that's it what I can think of

```cpp
class Solution {
public:
    void doBfsFromEdges(queue<pair<int,int>>&q,
    vector<vector<char>>& board,
    int rows,
    int cols,
    vector<vector<bool>>&visited,
    vector<vector<bool>>&keepTrack
    ){
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right

while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for (auto [dx, dy] : directions) {
        int newX = x + dx, newY = y + dy;

        if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && board[newX][newY] == 'O' && !visited[newX][newY]) {
            q.push({newX, newY});
            visited[newX][newY] = true;
            keepTrack[newX][newY] = true;
        }
    }
}


    }
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> keepTrack(rows, vector<bool>(cols, false)); // initially all false
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        for (int j = 0; j < cols; j++) { // Top row
            if (board[0][j] == 'O' && !visited[0][j]) {
                q.push({0, j});
                visited[0][j] = true;
                keepTrack[0][j] = true;
            }
        }

        for (int i = 1; i < rows; i++) { // Right column
            if (board[i][cols - 1] == 'O' && !visited[i][cols - 1]) {
                q.push({i, cols - 1});
                visited[i][cols - 1] = true;
                keepTrack[i][cols - 1] = true;
            }
        }

        for (int j = cols - 2; j >= 0; j--) { // Bottom row
            if (board[rows - 1][j] == 'O' && !visited[rows - 1][j]) {
                q.push({rows - 1, j});
                visited[rows - 1][j] = true;
                keepTrack[rows - 1][j] = true;
            }
        }

        for (int i = rows - 2; i > 0; i--) { // Left column
            if (board[i][0] == 'O' && !visited[i][0]) {
                q.push({i, 0});
                visited[i][0] = true;
                keepTrack[i][0] = true;
            }
        }

        doBfsFromEdges(q, board, rows, cols, visited, keepTrack);

        // Convert unmarked 'O' cells to 'X'
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O' && !keepTrack[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    


    }
};
```