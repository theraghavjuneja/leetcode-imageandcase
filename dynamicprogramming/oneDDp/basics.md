Sure! I'll **rewrite everything cleanly** — corrected spelling, fixed C++ code, structured explanations — so it looks neat and professional.

---

# Dynamic Programming - Fibonacci Example

## Key Idea
Dynamic programming solves problems by breaking them into smaller subproblems and storing the results to avoid redundant work.

Example:  
The Fibonacci sequence is defined as:
\[
F(n) = F(n-1) + F(n-2)
\]

---

# 1. Simple Recursive Solution (Without DP)

```cpp
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 5;
    cout << fibonacci(n) << endl;
    return 0;
}
```
**Problem:**  
This method recalculates the same values many times — exponential time complexity \(O(2^n)\).

---

# 2. Memoization (Top-Down DP)

Store the results of previous computations in a `dp` array.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n, vector<int>& dp) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
}

int main() {
    int n = 5;
    vector<int> dp(n + 1, -1); // Initialize dp array with -1
    cout << fibonacci(n, dp) << endl;
    return 0;
}
```
**Time Complexity:** \(O(n)\)  
**Space Complexity:** \(O(n)\) (due to recursion stack + dp array)

---

# 3. Tabulation (Bottom-Up DP)

Iteratively build the solution from base cases.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 6;
    vector<int> dp(n, -1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i < n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n-1] << endl; // Output nth Fibonacci number
    return 0;
}
```
**Time Complexity:** \(O(n)\)  
**Space Complexity:** \(O(n)\)

---

# 4. Space Optimization (Only O(1) Space)

Since Fibonacci depends only on the last two values, we don't need the entire array.

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 6;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    int prev2 = 0;
    int prev1 = 1;

    for (int i = 2; i < n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1 << endl;
    return 0;
}
```
**Time Complexity:** \(O(n)\)  
**Space Complexity:** \(O(1)\)

---

# Summary

| Approach            | Time Complexity | Space Complexity |
|---------------------|------------------|------------------|
| Simple Recursion    | \(O(2^n)\)       | \(O(n)\) (stack) |
| Memoization (Top-Down) | \(O(n)\)      | \(O(n)\)         |
| Tabulation (Bottom-Up) | \(O(n)\)       | \(O(n)\)         |
| Space Optimized      | \(O(n)\)         | \(O(1)\)         |

---

# Concept Explanation

- **Memoization (Top-Down):**  
  Start from the required value \(n\), break down into subproblems recursively, and store already computed results to avoid recomputation.

- **Tabulation (Bottom-Up):**  
  Start from the smallest subproblem (base case) and iteratively build up the solution.

- **Transition from Memoization to Tabulation:**  
  - Write base cases manually.
  - Use a `for` loop to compute next values using the recurrence relation.

---

Would you also like me to make a small diagram showing the recursion tree (how `fibonacci(5)` splits into `fibonacci(4)` and `fibonacci(3)` etc)? 📈  
It can make understanding memoization even clearer!

#### Types of Problems that I encountered throughout
- Distinct Ways: I added up all the ways . dp[0]+dp[1], dp[1]+dp[2] to build final soln(Example problem 70 climbing stairs)
- Min Cost: So here, if we go out of bounds we will return a very large no to ephasize that we should not take this path. Else we will always do the min of all paths one can encoutner
