## 2874 MaxTriplet2

### Problem Description:
The problem is the same as problem **2873**, but the solution needs to be optimized to run in **O(n)** time complexity.

### Approach:
Let's consider the given test case:

```cpp
[12, 6, 1, 2, 7]
```

Initially, I thought about using **dynamic programming (DP)**, but it becomes too complicated as there are three changing variables with multiple conditions, which makes the approach non-intuitive. Instead, let's try to traverse the array and think through the problem step by step.

### Steps:

#### Test Case Analysis:
Consider the array `[12, 6, 1, 2, 7]`. We want to find the **maximum triplet value** possible. Let's break it down:

For position **0**, where the value is `12`, the possible conditions are:

- `(12 - 6) * 7`
- `(12 - 7) * 2`
- `(12 - 2) * 1`
- The maximum value from these conditions would be **(12 - 1) * 7**.

#### Observation:
The best result occurs when:

- **i** (the first element) is the **maximum value**.
- **k** (the last element) is the **maximum value**.

Thus, we can achieve the maximum value by maintaining some sort of **prefix** and **suffix** data.

### Optimized Solution:
We can solve this problem by maintaining:

- **prefixMax**: The maximum value encountered from the left up to the current position.
- **suffixMax**: An array where each element at index `i` contains the maximum value from the elements to the right of index `i`.

#### Algorithm:
1. Traverse the array from left to right.
2. For each element at index `j`, calculate the triplet value using `prefixMax`, `nums[j]`, and `suffixMax[j]`.
3. Keep track of the **maximum triplet value** encountered.

### Code Implementation:

```cpp
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int sMax = nums[nums.size() - 1];
        vector<int> suffixMax(nums.size(), 0);

        // Fill suffixMax array
        for (int i = suffixMax.size() - 2; i >= 0; i--) {
            suffixMax[i] = max(nums[i + 1], sMax);
            sMax = suffixMax[i];
        }

        long long answer = 0;
        int prefixMax = nums[0];

        // Traverse and calculate the maximum triplet value
        for (int j = 1; j < nums.size() - 1; j++) {
            long long val = ((long)prefixMax - (long)nums[j]) * (long)suffixMax[j];
            answer = max(answer, val);
            prefixMax = max(prefixMax, nums[j]);
        }

        return answer;
    }
};
```

### Explanation:

#### **Suffix Max Array:**
We build the `suffixMax` array where each element at index `i` stores the **maximum value** from `nums[i+1]` to the **end** of the array. This helps us efficiently compute the value of the triplet involving `nums[i]` and `nums[k]`.

#### **Prefix Max Value:**
We also maintain `prefixMax`, which holds the **maximum value** from the left side up to index `j` (the current element).

#### **Triplet Calculation:**
For each `j`, the value of the triplet is calculated as:

```cpp
((prefixMax - nums[j]) * suffixMax[j])
```

We update `answer` with the **maximum value** encountered during the traversal.

### **Time Complexity:**
The time complexity is **O(n)** where `n` is the size of the input array, as we only traverse the array **twice** (once to build the `suffixMax` array and once to calculate the maximum triplet value).