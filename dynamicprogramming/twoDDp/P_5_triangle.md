---

```markdown
# Triangle Minimum Path Sum – 3 Approaches

This document explains three different approaches to solving the **Triangle Minimum Path Sum** problem. The problem is to find the minimum path sum from the top to the bottom of a given triangle, where at each step you may move to adjacent numbers on the row below.

## Problem Statement

You are given a triangle array, return the minimum path sum from top to bottom.

Each step you may move to the adjacent numbers in the row below, i.e., if you are at index `j` in the row `i`, then you can move to index `j` or `j+1` in row `i+1`.

---

## Approach 1: **Recursive + Memoization (Top-Down DP)**

### 🔍 **Intuition**

Start from the top of the triangle and recursively move down. At each index `(i, j)`, choose the minimum of the two paths going down to `(i+1, j)` and `(i+1, j+1)`. Use memoization to avoid recomputation.

### ⏱️ Time Complexity
**O(n²)**  
Every index is visited only once and stored in the memoization table.

### 🧠 Space Complexity
**O(n²)** for the memoization table + **O(n)** recursion stack.

### ✅ Code

```cpp
class Solution {
public:
    int f(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (i == n - 1) return triangle[i][j];
        if (dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + f(i + 1, j, n, triangle, dp);
        int downRight = triangle[i][j] + f(i + 1, j + 1, n, triangle, dp);
        
        return dp[i][j] = min(down, downRight);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, 0, n, triangle, dp);
    }
};
```

---

## Approach 2: **Tabulation (Bottom-Up DP - Explicit Initialization)**

### 🔍 **Intuition**

We build the `dp` table from the top, filling the minimum cost to reach each cell. At every cell `(i, j)`, we take the min from the previous row’s `j` and `j-1`, only if valid.

### ⏱️ Time Complexity
**O(n²)** – We fill each cell of the triangle once.

### 🧠 Space Complexity
**O(n²)** – For storing the entire `dp` matrix.

### ✅ Code

```cpp
class Solution {
public:
    int tabulation(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (i == 0 && j == 0) {
                    dp[0][0] = triangle[0][0];
                    continue;
                }
                int down = 1e9, downRight = 1e9;

                if (i > 0 && j < i)
                    down = triangle[i][j] + dp[i - 1][j];
                if (i > 0 && j > 0)
                    downRight = triangle[i][j] + dp[i - 1][j - 1];

                dp[i][j] = min(down, downRight);
            }
        }

        int ans = 1e9;
        for (int i = 0; i < m; i++)
            ans = min(ans, dp[n - 1][i]);
        return ans;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return tabulation(triangle);
    }
};
```

---

## Approach 3: **Tabulation (Bottom-Up - In-Place Optimization)**

### 🔍 **Intuition**

We start from the second-last row and move upward. At each index, we update the current cell with the min path sum of its two children below. This modifies the triangle in-place or in a copied DP array.

### ⏱️ Time Complexity
**O(n²)** – One traversal over the triangle.

### 🧠 Space Complexity
**O(n²)** – If using a separate `dp` array.  
Can be reduced to **O(n)** if optimized to use a single row.

### ✅ Code

```cpp
class Solution {
public:
    int tabulation2(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp = triangle;

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] += min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return tabulation2(triangle);
    }
};
```

---

## ✅ Conclusion

| Approach              | Time Complexity | Space Complexity | Notes                           |
|-----------------------|------------------|------------------|----------------------------------|
| Recursive + Memoization | O(n²)             | O(n²) + O(n)      | Easy to understand, less efficient |
| Bottom-Up DP (Tabulation) | O(n²)           | O(n²)            | Classic iterative DP approach     |
| Bottom-Up In-Place     | O(n²)             | O(n²) (can be O(n))| Most optimized in practice       |

### Now for space optimization,
- At any time dp is dependent on next row(which i already traversed)
- so i will start by only keeping the next row in dp table
- and then i will update current row based on dp[j],dp[j+1].
```cpp
int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n - 1];  
        // i will only store one dp row (initialized with last)
        // now since for current row i only need next row which i have in dp
        // based on thsi current row dp[j]=tr[i][j]+min(dp[j],dp[j+1]);
        // dp[j] is element just below, dp[j+1]is below right
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }

        return dp[0]; // Final result is at the top
    }
```




````