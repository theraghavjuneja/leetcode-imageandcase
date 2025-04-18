### 2817 Minimum Absolute Difference Between Elements With Constraint
### Problem Statement
- Given an array, and an integer x, what I need to do?
- I need to find minimum abs differeence between elements in array atleast x indices apart
- Okay in easy way lets imagine this array [4,3,2,4]
- At index 0, element=4, what elements I can consider for subtraction? Which are atleast x =2 indices apart i.e. element=2 (index 2 ), element=4(index 4). So 4-2=2 4-4=0(minimum). I need to do this for each index by looking x indices apart or backward. I will look only in one direction probably backward, to avoid redundant calculations.
- Okay so this will form the basis of bruteforce soln, right?
### Maybe something like
```
for loop(i) (from i=x to i=n)
Now, for each index i need to go from 0 to i-x, and check whether on subtracting that with current element (index i), what we get? Right?
```
#### Now above will form an O(n^2) solution. How to go to O(nlogn ) perhaps?
- Just imagine first loop (from i=x to i=n)
- Now for each i , what I am doing?
- I am going from index 0 to i-x, right? Since this is the place where 2nd number can be found?
- But we are doing this again and again,
- Imagine i=2, x=2 I will check for 2nd element at index=0
- Imagine i=3, x=2 now i will check 2nd element at index=0, index=1, So why again index=0?
- Why can't I just store it somewhere and then find? Isn't it?
- So i will traverse from i=x to i=n, and then will push nums[j-x] to the set? Sounds good? Yes!!
- Now say element is 4, I need to find nearest element to 4 in the set. THat can easily be done using lower_bound & upper_bound.
- So i will be using lower bound to find an element just greater than equal to 4.
- Now what if element was smaller than 4? For that I will be going one step backward

### Okay another example set{1,5,8} num=6, 
### Lower bound will give num=8 (just greater), but answer would be 5, as 6-5<8-6. So we try moving low one place backward and check whether that diff is more smaller

```cpp
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> st;
        int minDifference = INT_MAX;
        for (int j = x; j < nums.size(); j++) {
            st.insert(nums[j - x]);
            
            auto low = st.lower_bound(nums[j]); //*low will give the element, low is just the iterator
            //okay so low will give element just greater than it, imagine if no element is greater(low is itself the greatest) than it will give st.end()
            // example [1,2,3,4] x=3 it gave st.end()
            
            if (low != st.end()) {
                minDifference = min(minDifference, abs(nums[j] - *low));
            }

            // [1,2,3,4] x=3 low is at st.end(), so just go one step back you get the element which is 1, and calculate minDifference
            // okay and say an set like {1,5,8}. and element=6 low will point to 8, but 5 was more closer?
            // so if low!=st.begin(), go one step backward and check the difference
            if (low != st.begin()) {
                --low;
                minDifference = min(minDifference, abs(nums[j] - *low));
            }
        }
        return minDifference;
    }
};
```