### Okay so let us try to understand the problem statement first.
- I am a professional rober. And I need to rob the maximum money out (ofcourse since I am a robber). Now given an array which represents the loot present in each house, what I need to do is
- > I need to rob houses with constraint that I cant rob adjacent houses. So for any of you who don't know this is a very traditional DP problem (or recursion) which says take the element or not take the element. i.e. take the house or not take the house
- this is what I need either I will take(if i didnt take previous, or I wont)
- one way for this is I can declare a bool which represents whether last house taken or not
- (but this will become complicated)
#### So instead what we will do is if i take i will send recursion request to index-2, instead of index-1

#### Okay so i will start with recursion. See a top-down approach. i.e. I will go in oppsoite
- imagine arr[1,2,3,1] Starting from last1, if i take it. I can go to 2. if i dont take 2, i will go to 1 and so on.
So for each element I will think to take it or not take it\
- Imagine i dont take1, and then take 3, then take first 1(sum=4) (max)
- now lets think base case. See if i reached index==0, that means i should take it. (Since if i dont take it , (no use) as we are maximizing the answer).
```cpp
int f(int index,vector<int>&nums,vector<int>&dp){
        // so if i take i will send request to index-2
        // else i will send to index-1
        if(index==0){
            return nums[0];
        }
        if(index<0){
            return 0; // meaning even if it adds it doesnt do any effect (like if i go out of bounds, by adding this (then return 0, as 0+something=0))
        }
        if(dp[index]!=-1) return dp[index];
        int take=nums[index]+f(index-2,nums,dp);
        int notTake=f(index-1,nums,dp);
        return dp[index]=max(take,notTake);

    }
```


#### now our step is to convert this memoization to tabulation which is so easy 
- follow 3 steps
- write base case
- form loops
- then write condition 
```cpp
 int tabulation(int index,vector<int>&nums){
        vector<int>dp(nums.size(),-1);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>=2){
                take+=dp[i-2];
            }
            int notTake=dp[i-1];
            dp[i]=max(take,notTake);
        }
        return dp[index-1];
    }
```