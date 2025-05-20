```cpp
class Solution {
public:
    int f(int i,int j,int m,int n,vector<vector<int>>&dp,vector<vector<int>>&obstacleGrid){
        // current indexes and end indexes
        if(i>=m||j>=n||i<0||j<0||obstacleGrid[i][j]==1) return 0;

        if(i==0&&j==0) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int comeFromLeft=f(i-1,j,m,n,dp,obstacleGrid);
        int comeFromTop=f(i,j-1,m,n,dp,obstacleGrid);
        return dp[i][j]=comeFromLeft+comeFromTop;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,m,n,dp,obstacleGrid);
    }
};

```
### Above is the soln of grid unique path with one extra base case only (Rest all is still the same)
```cpp
int tabulation(vector<vector<int>>&obstacleGrid){
        
        int m=obstacleGrid.size();

        int n=obstacleGrid[0].size();
         vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0&&obstacleGrid[i][j]==0){
                    dp[0][0]=1;
                    continue;
                }
                
                int ans=0;
                if(i>0){
                    // cout<<"Called"<<endl;
                    ans+=dp[i-1][j];
                }
                if(j>0){
                    // cout<<"Called j"<<endl;
                    ans+=dp[i][j-1];
                }
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;

                }
                else dp[i][j]=ans;
            }

        }
        
        return dp[m-1][n-1];

    }
```