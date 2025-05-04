# Intuition
1. Let's try to understand the problem statement
2. I am at top left position. Need to reach bottom right position with minimizing the sum of numbers along the path. So, we need to return that minimum sum when we go from top left to bottom right..
3. Now, at any point I can move either down or right? And our destination is bottom right
4. Now, what if someone tries to do it greedily? For instance trying to go to right and bottom.(and the one which is smaller, he will go there). But this is not a correct approach as we need to minimize the sum not individual or local things. We need to think globally
5. So, greedy won't work
6. ## Recursion
    o Recursion says I will go from bottom right to top-left. (i.e. a top-down approach). So I will start at bottom right and will make rec calls like
    o **int comeFromLeft=grid[i][j]+f(i-1,j,n,m,grid,dp);**
    o **int comeFromTop=grid[i][j]+f(i,j-1,n,m,grid,dp);**
    o Anytime I will return the min of these calls, right? So this is taking into consideration whole matrix
    o Now, what will be the base cases. I i reach i==0 &&j==0(Base cases). So here i will reach arr[i][j] or arr[0][0] as top-left will ofcourse always be present
    o Out Of Bounds? Yes say i went out the array, then i should return a sufficiently large number like 1e9, so that that path is not taken. (Avoid returing INT_MAX, as it is being added, so that will cause a overflow)..

    o So, that will be recursion(But complexity O(2 raise n)). At every cell i am making 2 calls top,left. And each cell is further making 2. so that becomes 2 ^n calls So time complexity= exponential

    o Now, our aim is to convert  this into DP. Now , 2 things i &j are changing, so I will take a 2-D DP table and initialize it to -1 then follow the approach

---



##  Approach: Dynamic Programming – Memoization (Top-Down)

1. **Goal**: We need to **minimize the sum** of numbers from the top-left `(0, 0)` to the bottom-right `(n-1, m-1)` of the grid, where only **right or down moves** are allowed.

2. **Recursive Structure**:

   * Let `f(i, j)` be the **minimum path sum** to reach cell `(i, j)` from `(0, 0)`.
   * To reach `(i, j)`, I could have come either from:

     * The cell **above**: `(i-1, j)`
     * The cell **to the left**: `(i, j-1)`
   * So, recurrence becomes:

     ```python
     f(i, j) = grid[i][j] + min(f(i-1, j), f(i, j-1))
     ```

3. **Base Case**:

   * If we reach the **starting cell (0, 0)**, return `grid[0][0]`.
   * If `i < 0` or `j < 0` (out of bounds), return a **large value** like `1e9` to invalidate that path.

4. **Memoization**:

   * Since `i` and `j` both vary, use a **2D DP table `dp[n][m]`** initialized to `-1` to store already computed results.
   * Before computing `f(i, j)`, check if `dp[i][j] != -1`. If so, return the stored value to avoid recomputation.

5. **Time Complexity**:

   * Each subproblem `(i, j)` is computed only once → Total subproblems = `n * m`.
   * Each subproblem does `O(1)` work.
   * **Total Time Complexity = O(n \* m)**
   * **Space Complexity = O(n \* m)** for the DP table + O(n + m) recursion stack depth.

6. **Next Step**:

   * This can be further optimized using **Tabulation (Bottom-Up)** or **Space Optimization**, but Memoization gives a very clear top-down view with little overhead.

Would you like me to convert this approach into clean Python or C++ code with memoization?

# Complexity
- Time complexity:
O(n*m)

- Space complexity:
O(n*m)

# Code (Memoization)
```cpp []
class Solution {
public:
    int f(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        
        if(i==0&&j==0)return grid[0][0];
        if(i<0||j<0) return  1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int sumFromTop=grid[i][j]+f(i-1,j,grid,dp);
        int sumFromLeft=grid[i][j]+f(i,j-1,grid,dp);
        return dp[i][j]=min(sumFromTop,sumFromLeft);

    }

    int minPathSum(vector<vector<int>>& grid) {
        int i=grid.size();
        int j=grid[0].size();
        vector<vector<int>>dp(i,vector<int>(j,-1));
        return f(i-1,j-1,grid,dp);
    }
};
```
### Now we will convert this into tabulation. Bottom-UP Dp.
Here are general steps:
1. Form DP table
2. Write Base case
3. Write for loops (Depending upon the memoization). Here we need to fill n*m cells. so 2 for loops will be needed
4. Now copy the recurrence relation from memoization soln. And that's it we are done now..
```cpp
int tabulation(vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0){
                    dp[0][0]=grid[0][0]; //base case, You can also write outside the loop
                    continue;
                }
                int comeFromLeft=1e9;
                int comeFromTop=1e9;
                if(i>0){
                    comeFromLeft=grid[i][j]+dp[i-1][j];
                }
                if(j>0){
                    comeFromTop=grid[i][j]+dp[i][j-1];
                }
                dp[i][j]=min(comeFromLeft,comeFromTop);
            }
        }
        return dp[n-1][m-1];
    }
```

