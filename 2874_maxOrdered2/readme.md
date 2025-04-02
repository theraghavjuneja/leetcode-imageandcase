# 2874 MaxTriplet2
### Problem Description: Same as 2873 , just here I need O(n) solution..
- Okay , so let me consider the given test case [12,6,1,2,7]
- Firstly, I thought of using dp, but there will be 3 changing vars with multiple conditions so not at all intuitive
- Now , let me just traverse array and think
```cpp
[12,6,7,2,1]
```
- At position 0, I have 12 say i=12, Now what are the conditons that can be formed? they will be
- (12-6)*7/2/1
- (12-7)*2/1
- (12-2)*1
- Now what will be max , it will be (12-1)*7 
- In short if i is maximum and k is maximum, we can achieve maximum Value ..

- I just need to maintain some sort of prefix/suffix.. Now since I will be traversing from l->r i will maintain a suffix vector and prefixMax (integer)
- Say, I am at position i, suffixVector will store the max value of nums from i+1... to nums.size()-1 (wont include nums[i])
``cpp
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int sMax=nums[nums.size()-1];
        vector<int>suffixMax(nums.size(),0);
        for(int i=suffixMax.size()-2;i>=0;i--){
            suffixMax[i]=max(nums[i+1],sMax);
            sMax=suffixMax[i];
        }
        long long answer=0;
        int prefixMax=nums[0];
        for(int j=1;j<nums.size()-1;j++) // j traverse
        {
            long long val=((long)prefixMax-(long)nums[j])*(long)suffixMax[j];
            answer=max(answer,val);
            prefixMax=max(prefixMax,nums[j]);
        }
        return answer;

    }
};
```