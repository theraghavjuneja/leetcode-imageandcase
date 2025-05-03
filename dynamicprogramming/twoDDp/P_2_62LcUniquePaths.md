You're on the right track! This is indeed a **2D Dynamic Programming "Count Ways"** type 
### ✅ Problem Statement:

You are given a grid of size `m x n`. You start at the **top-left corner** of the grid (cell `(0,0)`) and you want to reach the **bottom-right corner** (cell `(m-1,n-1)`). At any point in time, you can only move **either right or down**.

You need to **count the number of unique paths** from the top-left to the bottom-right corner.

---

### 🔍 Understanding the Approach:

This is a **classic DP problem**. The idea is:

* From each cell `(i,j)`, the number of ways to reach it is the **sum of ways to reach**:

  * The cell above it `(i-1, j)` (if valid)
  * The cell to the left of it `(i, j-1)` (if valid)

We use a **DP table** to **memoize** overlapping subproblems.
But see, it is a classic problem of number of ways. Here we take sum of all ways we can have at any time

---

### 🧠 Base Case:

If we're at cell `(0,0)`, that's our **starting point** → **only 1 way** to be there: stay there.

If `i < 0` or `j < 0`, that means we're out of bounds → **0 ways**.

---

### ✅ Corrected Code:

```cpp
int f(int i, int j, vector<vector<int>>& dp) {
    if (i < 0 || j < 0) return 0;         // Out of bounds
    if (i == 0 && j == 0) return 1;       // Base case
    if (dp[i][j] != -1) return dp[i][j];  // Memoization check

    int fromTop = f(i - 1, j, dp);
    int fromLeft = f(i, j - 1, dp);
    
    return dp[i][j] = fromTop + fromLeft;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, dp);  // Start from bottom-right
}
```

---

### 📦 Time & Space Complexity:

* **Time Complexity**: `O(m * n)` due to memoization.
* **Space Complexity**: `O(m * n)` for the DP table (can be optimized to `O(n)` if needed).

---

### 💡 Follow-up:

* What if some cells are **obstacles** (blocked)? You'd need to skip those by checking a condition inside the recursive function. (Leetcode 63)
* Can you solve it using **bottom-up tabulation**?( Yes, given below)
* Can you do it in **1D space** for optimization? (Yes, we can)

#### Bottom-Up Tabulation Approach

```cpp
int tabulation(int m,int n){
        vector<vector<int>> dp(m, vector<int>(n, 0));
    
        // Base case: there's only one way to reach cell (0,0)
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // i=0,j=0 already in base case
            if (i > 0)
                dp[i][j] += dp[i - 1][j];  // Coming from top
            if (j > 0)
                dp[i][j] += dp[i][j - 1];  // Coming from left
        }
    }
    return dp[m-1][n-1];
    }
```