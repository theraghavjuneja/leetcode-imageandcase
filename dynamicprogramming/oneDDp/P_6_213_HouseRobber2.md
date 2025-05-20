### So here it's a circle, so i cant take two together. Rest all same just n-1 & 0 cant be togethter
#### Will right both correct & wrong approach
### Correct
- 1. Exclude the last house and include the first
- 2. Exclude the first house and include the last 
### And we will take maximu. Exclude here means the last house wont be taken. (Doesnt mean that i will necerrarily take first, say 2+4+6 (7 last)) gave me better than 1+3+5 etc. so i will take that

- this is a general statement that exlude last, include first & vice versa. then check which is giving max answer

### From parent function, i will make 2 calls one in which last is excluded and first included and vice versa.

### Performing using memoization
```cpp
class Solution {
public:
    int f(bool takeFirst,int index,vector<int>&nums,vector<int>&dp){
        if(index==0){
            if(takeFirst){
                // Take first element only if takeFirst is true, else explicitly return 0
                return nums[0];
            }
            return 0;
        }
        if(index<0){
            return 0;
        }
        if(dp[index]!=-1) return dp[index];
        int take=nums[index]+f(takeFirst,index-2,nums,dp);
        int notTake=f(takeFirst,index-1,nums,dp);
        return dp[index]=max(take,notTake);

    }
    int rob(vector<int>& nums) {  
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int>dp(nums.size(),-1);
        int val1=f(false,nums.size()-1,nums,dp); // Dont take first element. Try to take last (Jaruri nhi ki last leinge, we will try to take, else it depends on take not take dp)
        for(int i=0;i<dp.size();i++){
            dp[i]=-1; // Due to first recursion call dp should have been filled, so replace again by -1
        }
        int val2=f(true,nums.size()-2,nums,dp); // Dont take last. So i started with element-2 (i.e. index-2) skipped last
        return max(val1,val2);

    }
};
```


### What if i try to share the dp? (Wrong approach)
- both of the recursive calls share same dp-> overlapping-> incorrect memoization when trying different constraints(including or excluding first/last element)
- even if i make conditionals like if -else inside a shared dp, still that will lead to overlap

### Tabulation
```cpp
int tabulation(vector<int>&nums){
    if(nums.size()==1) return nums[0];
    if(nums.size()==2) return max(nums[0],nums[1]);
    vector<int>dp(nums.size(),-1);
// Case 1: Include first, exclude last
    dp[0]=nums[0]; // max answer till index 0=nums[0]
    for(int i=1;i<nums.size();i++){
        int take=nums[i];
        if(i>=2){
            take+=dp[i-2];
        }
        if(i==nums.size()-1) take=0; // avoid taking last
        int notTake=dp[i-1];
        dp[i]=max(take,notTake);
        }
    int val1=dp[nums.size()-1];
    fill(dp.begin(), dp.end(), -1); // replaced every element with -1 to avoid voerlap
    // Case 2: Exclude first
    dp[0]=0;
    for(int i=1;i<nums.size();i++){
        int take=nums[i];
        if(i>=2){
            take+=dp[i-2];
        }
        int notTake=dp[i-1];
        dp[i]=max(take,notTake);
    }
    int val2=dp[nums.size()-1];

    return max(val1, val2);
int rob(vector<int>&nums){
    return tabulation(nums);
}
```