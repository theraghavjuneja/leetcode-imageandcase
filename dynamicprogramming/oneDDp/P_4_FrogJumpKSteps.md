### so this is the modified version of frog jump . Just I can take k jumps at a time. Remember that
![image](3,4_frogJumo.jpg)
```cpp
int memoizedSolution(int index,vector<int>&cost,vector<int>&dp,int k)
    {
        if(index<0) return 1e9; //to emphasize this is very high cost and this route shouldnt be taken
        if(index==0) return 0;
        if(dp[index]!=-1) return dp[index];
        
        // int goOneBefore = memoizedSolution(index - 1, cost, dp) + abs(cost[index] - cost[index - 1]);
        // int goTwoBefore = (index > 1) ? memoizedSolution(index - 2, cost, dp) + abs(cost[index] - cost[index - 2]) : INT_MAX;
        int CostToComeFromIndexI=INT_MAX;
        for(int i=index-k;i<index;i++){
            CostToComeFromIndexI=min(CostToComeFromIndexI,memoizedSolution(i,cost,dp,k)+abs(cost[index]-cost[i]));
        }
        
        return dp[index] = CostToComeFromIndexI;
        

    }
```
#### so i can then just directly convert this solution to tabulation
```cpp
 int tabulation(int n, int k, vector<int> &height){
        vector<int>dp(height.size(),-1);
        dp[0]=0;
        for(int i=1;i<height.size();i++){
            int CostToComeFromIndexJ=INT_MAX;
            // now for each i can go to k steps bakc
            for(int j=i-k;j<i;j++){
                if(j>=0)
                {
                    CostToComeFromIndexJ=min(CostToComeFromIndexJ,dp[j]+abs(height[i]-height[j]));
                }
                
            }
            dp[i]=CostToComeFromIndexJ;
        }
        return dp[n-1];
 }
 ```