#### Okay so I am climbing a staircase. It takes me n steps to reach the top. (I took 1 or 2 step each time)
#### Problem says to find total ways to reach the top
- Imagine i am at stair 1, I can go to 2 or 3. Then 2 also I can go to 3 or 4 and so on.. So after climbing each stair I have 2 options and so on it goes like. Each of this become a separate sub-problem. (This is how it works).
- Okay so there are all this separate sub-problems. So , each sub-prob-> Recursion . So i will start with recursion
- recursion means topDown. 
- imagine I am at n=4. i will see from where i can come n=3 or n=2. And then at n=3 i can see from where I can come and so on


### Top-down recursion 
- i will start from end (or top), then will go down.
- so imagine i am at n=5, then I may have come from 4 or 3. then at 4 I may have come from 3 or 2. And so on it goes on... 
```cpp
int memoizedSolution(int index,vector<int>&dp){
        if(index<0) return 0;
        if(index==0) return 1;
        if(dp[index]!=-1) return dp[index];
        else return dp[index]=memoizedSolution(index-1,dp)+memoizedSolution(index-2,dp);
    }
```

### Now tabulation will be just the oppsoite. It says I will start from bottom(n=0) and then I will add up all solns to reach the toppest place
```cpp
int tabulation(int n)
    {
        // tabulation bottom-up,
        // for going or finding n=5, i will start building solution from 0
        vector<int>dp(n+1,-1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            int addSecond=i>=2?dp[i-2]:0;
            dp[i]=dp[i-1]+addSecond;
        }
        return dp[n];
    }
```
