```cpp
#include <bits/stdc++.h> 
bool f(int index,vector<int>&arr,int requiredSum,vector<vector<int>>&dp){
    if(requiredSum==0) return true;
    if(index==0){
        return arr[index]==requiredSum;
    }
    bool take=false;
    if(requiredSum>=arr[index]){
        take=f(index-1,arr,requiredSum-arr[index],dp); //if this is not done then we may access negative dp
    }
    bool notTake=f(index-1,arr,requiredSum,dp);
    return dp[index][requiredSum]=take||notTake;
}
bool tabualation(int n,int k,vector<int>&arr){
    vector<vector<int>>dp(n,vector<int>(k+1,0)); //filled with 0, otherwise I would have to 
    // take another loop for filling index 0 with zeros
    for(int i=0;i<n;i++){
        dp[i][0]=1; //if sum is 0, then be it any index return true
    }
    if(arr[0]<=k){
        dp[0][arr[0]]=true;
    }
    // i is on index, j on target
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool take=false;
            if(j>=arr[i]){
                take=dp[i-1][j-arr[i]];

            }
            bool noTake=dp[i-1][j];
            dp[i][j]=take||noTake;
        }
    }
    // for(int i=0;i<dp.size();i++){
    //     for(int j=0;j<dp[i].size();j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[n-1][k];
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return tabualation(n,k,arr);
    // vector<vector<int>>dp(n,vector<int>(k+1,-1));
    // return f(n-1,arr,k,dp);
}
```