## The question is saying that I need to find all those triplets whose sum is 0

Unlike 2 sum, the numbers can be repeated in the array, so we must make sure that if 3 numbers appear [a,b,c] [c,a,b] [c,b,a] etc. they refer to the same thing [a,b,c].

(These can also be said as anagrams, remember whenever we get sequences where the same elements appear regardless of order, an optimal approach is sorting)

But before sorting I will start with how I thought it from, and also write about custom hash etc.

## Extreme Bruteforce Approach

```cpp
vector<vector<int>> answer;
for(int i=0;i<nums.size()-2;i++){
    for(int j=i+1;j<nums.size()-1;j++){
        for(int k=j+1;k<nums.size();k++){
            whenever the sum of all 3 is equal to k, we append them to the vector
        }
    }
}
```

Now, let us consider something like `[-1,0,1,2,-1,-4]`
Here `-1` appears 2 times, and also `-1+0+1=0` or `0+1+-1=0` (anything can be written), and the above code will give both of these, as there is repetition as well as I haven't sorted or used sets.
but question says we dont need repetition , so is there any ds which avoid repetition?

## Using a Set to Avoid Repetition

```cpp
vector<vector<int>> findTriplets(vector<int>& nums, int target) {
    vector<vector<int>> answer;
    set<vector<int>> uniqueTriplets;

    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if (nums[i] + nums[j] + nums[k] == target) {
                    vector<int> triplet = {nums[i], nums[j], nums[k]}; // a triplet
                    sort(triplet.begin(), triplet.end()); // sorting the triplet O(1) due to a 3-size window only
                    uniqueTriplets.insert(triplet); // insertion O(logn)
                }
            }
        }
    }
}
```

So in this case, the complexity is **O(n³ logn)** -> Extreme Bruteforce (that I could have thought of)

### Why I didn't use an unordered set above (in bruteforce)?
- **Reason**: `unordered_set<vector<int>> uniqueTriplets;` is in itself an error. (You can google/chat GPT, unordered sets or maps don't have a hash function for vectors. The hashes are defined for things like strings, chars, or integers by default. A custom hash would be needed here so you may develop your custom hash but that's generally not needed in interview, .)

## Why Sorting?

- See, when we arrange an array sometimes, for example `[a,b,c] -> [c,a,b], [c,b,a]` etc., these arrangements are called anagrams. (You can refer to the **valid anagrams** question.)
- When we sort them, we get the same thing, so this makes sure that always the same vector is appended in a set, and a vector that was already appended doesn’t get inside again.
- example [1,2,3] [3,1,2] [3,2,1] are anagrams which on sorting give same [1,2,3] that's what we actually required. Isn't it?

## Slightly More Optimal Approach: **O(n² logn)**

- I can eliminate one of the loops.
- How do we eliminate loops? **Sorting / Two Pointers / Unordered Maps**
- I will use a **set along with an unordered map**.

```cpp
vector<vector<int>> uniqueTriplets(vector<int>& nums) {
    vector<vector<int>> result;
    set<vector<int>> uniqueTriplets;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++) {
        unordered_map<int, int> ump; // first integer: number, second integer: count
        for (int j = i + 1; j < nums.size(); j++) {
            if (ump.find(-(nums[i] + nums[j])) != ump.end()) {
                vector<int> triplet = {nums[i], nums[j], -(nums[i] + nums[j])}; // triplet num1, num2, -(num1+num2)
                sort(triplet.begin(), triplet.end()); // O(1) since it's a size-3 triplet
                uniqueTriplets.insert(triplet);
            }
            ump[nums[j]]++;
        }
    }
    return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
}
```

This approach works because we loop through 2 numbers and check whether a **third** number exists such that the overall sum is equal to zero.

This is **good**, but not yet the most efficient approach.

## The Most Optimal Approach: **O(n²)**

Let's try to imagine a sorted array:

`-2,-2,-2,-2,-2,-2,-1,-1,-1,0,0,0,1,1,1,2,2,2,2,2,2`

(All equal elements together, right?)

1. Suppose I am traversing this array, and currently, I am at element `-2` (index `0`).
2. What if I declare **two pointers** at **position 1 and the last position**? (Let's call them `left` and `right`)
3. If `(-2 + (-2) + 2 = -2)`, that's **less than 0**. Now, I need to move `left` to increase the sum.
4. But how much left I should move, if I move one position left, i again get i again get 2 so why not use a while loop?
5. Skip duplicate numbers using a `while` loop.
6. Continue this logic until `left < right` and then move the fixed pointer (`i`).

7. but again fixed pointer also may have duplicates. from index 1 to 5 i have -2 only, so i can just write a continue statement that if current element matches previous so dont do anything just continue

### Optimized Code (Two Pointer Approach)

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    answer.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++; // Skip duplicates
                    while (left < right && nums[right] == nums[right - 1]) right--; // Skip duplicates
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return answer;
    }
};
```

### Final Complexity: **O(n²)**

This is the **most optimal** approach using **sorting and two pointers** to avoid unnecessary computations and ensure we find all unique triplets efficiently.

