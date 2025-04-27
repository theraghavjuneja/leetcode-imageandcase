## 3392 Count SubArrayf of Length 3 with A condition
- Given an array nums, I need to count no of subarrays such that num1+num3==(num2)//2 (eaxctly half)
- Since this is given we need exact half and only 3 numbers will always be there so I can easily use something like a sliding window (of fixed size 3) and can solve
```cpp
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count=0;
        int start=0;
        int end=2;
        while(start<nums.size()&&end<nums.size()){
            double num1=nums[start];
            double num2=nums[start+1];
            double num3=nums[end];
            if((num1+num3)==num2/2) count++;
            start++;
            end++;
        }
        return count;
    }
};
```