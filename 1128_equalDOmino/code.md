

# Domino Pairs - Explanation & Code

## Problem Understanding

The goal is to count the number of **equivalent domino pairs** in a given list. Two dominoes are considered **equal** if:

* They have the same numbers in the same order (e.g., `[1,2] == [1,2]`)
* Or, they can be rotated to match each other (e.g., `[1,2] == [2,1]`)

## Brute Force vs Hashmap Approach

### 🔹 Brute Force

Brute force is easy but inefficient for large inputs. It involves checking all possible pairs, which results in **O(n²)** time complexity.

### 🔹 HashMap Approach

The efficient approach uses a `HashMap` to store the frequency of normalized domino pairs.

> Initially, it was confusing to decide what to use as the key in the hashmap. If I simply used pairs like `1 -> 1` or `1 -> 3`, there would be conflicts since keys must be unique.
>
> So instead, I normalized each domino by always placing the **smaller number first** and combined them into a **two-digit integer** like `min*10 + max`.
>
> For example:
>
> * Domino `[1,2]` and `[2,1]` are both normalized as `12`.
> * Domino `[1,1]` is normalized as `11`.

This way, I can check if an equivalent domino has already been seen by just checking the hashmap with the normalized key.

## Algorithm

1. Iterate over each domino.
2. Normalize the domino by sorting the two values.
3. Convert the pair into a unique key using `min*10 + max`.
4. If the key exists in the hashmap:

   * Add its frequency to the count.
   * Increment the frequency in the map.
5. If not, insert it with frequency 1.
6. Return the final count.

## Code

```cpp
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> ump;
        int count = 0;

        for (int i = 0; i < dominoes.size(); i++) {
            int num1 = dominoes[i][0];
            int num2 = dominoes[i][1];
            int key = min(num1, num2) * 10 + max(num1, num2);

            count += ump[key];  // Add current frequency to count
            ump[key]++;         // Increment frequency
        }

        return count;
    }
};
```

## Time & Space Complexity

* **Time Complexity:** O(n)
* **Space Complexity:** O(1) (since the number of possible unique domino pairs is limited to 100)

---

Would you like a visual diagram to help explain the hashmap key generation?
