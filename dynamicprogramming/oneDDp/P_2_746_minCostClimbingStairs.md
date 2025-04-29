#### Okay so this is a cost (min cost) based problem
##### If you are new to these kind of problems one thing to remember
- If you get out of the bounds return 1e9 to emphasisze this is a very high cost
- else return the min of all paths available to you....
- this is all we need to do

#### Okay so problem explanation
- Imagine we are travelling in array. We can start from index 0 or index 1. Now at each instance i can jump 1 or 2 step. But before jumping i need to pay cost equavilane to the cost[i]. then i can jump either 1 or 2 steps that depend on me. 
- okay so let's say that I consider the given array
##### [10,15,20]. Now let's start with 10 <br>
<>
#### Okay so i am at 10. I can jump to 15 or 20. (cost +10)
#### Now say I went to 15. I can jump to 20 or out of array. Say i went to 20(cost+15)
#### I am at 20. Now I can jump to out of array(cost+20)
- so total cost if i go 10->15->20= 45
- i can also go like 10->20->out (Cost 10(for 10->20) +20(for 20->out))
- now if i start with 15 I can directly go out in 2 jumps (15->out)
- so min cost will be 15. 

#### Okay so how do we code this
- we will go from n to 0 (i.e. top-down) or recursion then I will try to memoize that solution
- okay so lets strat that
- okay i will bring up all solns to array end (imagine an ending space at arr after 20, (this is where I need to reach))
```cpp
int f(int index,vector<int>&cost){
        if(index<0) return 1e9; //to emphasize this is very high cost and this route shouldnt be taken
        if(index==0) return cost[0];
        if(index==1) return cost[1];
        int curr=0;
        if(index<cost.size()){
            curr=cost[index]; //okay so this is done for out of bounds as i am accumulating till n and not n-1. also arr[n] is nothing
        }
        int val1=curr+f(index-1,cost);
        int val2=curr+f(index-2,cost);
        return min(val1,val2);
        
    }
    //now to memoize this solution, i will introduce the standard way of dp
    int memoizedSolution(int index,vector<int>&cost,vector<int>&dp)
    {
        if(index<0) return 1e9; //to emphasize this is very high cost and this route shouldnt be taken
        if(index==0) return cost[0];
        if(index==1) return cost[1];
        if(dp[index]!=-1) return dp[index];
        int curr=0;
        if(index<cost.size()){
            curr=cost[index];
        }
        int val1=curr+memoizedSolution(index-1,cost,dp);
        int val2=curr+memoizedSolution(index-2,cost,dp);
        return dp[index]=min(val1,val2);

    }

```

### now i will try to tabulate the solutiom.
- so that means a bottom up approach. Peraps starting from 0 and then going upward till n
```cpp
int tabulation(vector<int>&cost){
        int n=cost.size();
        vector<int>dp(n+1,-1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<=n;i++)
        {
            int curr=0;
            if(i<n){
                curr=cost[i]; //again this is done as arr[n] is nothing I need to react there from prev steps, so cost only for those prev steps
            }
            int val1=curr+dp[i-1];
            int val2=curr+dp[i-2];
            dp[i]=min(val1,val2);
        }
        return dp[n];

    }
```