# 2873 Maximum value of An ordered Triplet 1
- Given an integer array nums
- I need to return maximum value over all triplets (i,j,k)
- Max value i (nums[i]-nums[j])*nums[k]
## Considering array [12,6,1,2,7]
- (12-1)*7 Answer
## Okay so I can feel that I need to maximize nums[i]-nums[j] Example max no=12 min=1 so (12-1)*7(as mut by 7 will be better)
- Since constraints are very small a soln with 3 nested loops would also work
- But yeah this is an O(n3) bruteforce
```cpp
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    long long val=((long)nums[i]-(long)nums[j])*(long)nums[k];
                    ans=max(ans,val);
                }
            }
        }
        return ans;
    }
};
```
- Okay but hell yeah, for O(n) soln It's max value of an ordered triplet 2 problem