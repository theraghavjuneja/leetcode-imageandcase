# What does the question say?
It says I need to find two integers which sum up to a target, (Given there will only be 2 unique integers for the same)

## So first is the extreme bruteforce that comes to my mind

- I can just create two variables i & j
- through these variables i can traverse the entire array
- and check at any time if arr[i] + arr[j] == target, since they will be unique no need of stuff like maps, sets, etc

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vect;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if((nums[i] + nums[j] == target)) {
                    vect.push_back(i);
                    vect.push_back(j);
                }
            }
        }
        return vect;
    }
};
```

## Now of course I need to reduce the complexity

- so things like 2 pointer sorting or maps are generally used for reducing complexity,
- What I can do is sort the array and then use 2 pointers (will give O(n log n)) ->

### Code might look something like

```
twoSum
sort the array
for loop
    variable i , variable j
    if target > sum i++
    else j--
```

O(n log n)

- now it can further be reduced if I use an unordered_map

### What I can do is simply ->

a.) I can create an `unordered_map<int,int>` first integer which number/element, second integer -> the index  
b.) on the fly check whether `target - num` has appeared before in map, if yes return true else false

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;
        
        for(int i = 0; i < nums.size(); i++) {
            int required = target - nums[i];
            if(ump.find(required) != ump.end()) {
                return {i, ump[required]};
            }
            ump[nums[i]] = i;
        }
        return {-1};
    }
};
```

