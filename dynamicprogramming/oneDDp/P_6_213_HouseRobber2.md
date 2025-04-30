class Solution {
public:
    // SOLUTION 1 
    // int f(bool takeFirst,int index,vector<int>&nums,vector<int>&dp){
    //     if(index==0){
    //         if(takeFirst){
    //             return nums[0];
    //         }
    //         return 0;
    //     }
    //     if(index<0){
    //         return 0;
    //     }
    //     if(dp[index]!=-1) return dp[index];
    //     int take=nums[index]+f(takeFirst,index-2,nums,dp);
    //     int notTake=f(takeFirst,index-1,nums,dp);
    //     return dp[index]=max(take,notTake);

    // }
    // int rob(vector<int>& nums) {  
    //     if(nums.size()==1) return nums[0];
    //     if(nums.size()==2) return max(nums[0],nums[1]);

    //     vector<int>dp(nums.size(),-1);
    //     // THIS CODE GIVES A CHECK OF NOT INCLUDING NUMS[0]
    //     int val1=f(false,nums.size()-1,nums,dp);

    //     for(int i=0;i<dp.size();i++){
    //         dp[i]=-1;
    //     }
    //     // THIS CODE GIVES A CHECK OF INCLUDING NUMS[0] AND NOT NUMS[NUMS.SIZE()-1]
    //     int val2=f(true,nums.size()-2,nums,dp);

    //     return max(val1,val2);

    // }
    int tabulation(vector<int>&nums){
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int>dp(nums.size(),-1);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>=2){
                take+=dp[i-2];
            }
            if(i==nums.size()-1) take=0; // so that this path not choosen
            int notTake=dp[i-1];
            dp[i]=max(take,notTake);
        }
        int val1=dp[nums.size()-1];
        for(int i=0;i<dp.size();i++){
            dp[i]=-1;
        }
        dp[0]=0; // i wont take the first element at all
        for(int i=1;i<nums.size();i++){
            
            int take=nums[i];
            if(i>=2){
                take+=dp[i-2];
            }
            int notTake=dp[i-1];
            dp[i]=max(take,notTake);
        }
        int val2=dp[nums.size()-1];
        return max(val1,val2);
    }

    // INSTEAD OF 2 SEPARATE CALLS I WILL TRY TO SOLVE IN ONE CALL
    // wrong approach (as override hojaayega)
    // we will need 2 seprate calls only so that take's dp doesnt override not take and vice versa
    // int f2(bool takeFirstElement,int index,vector<int>&nums,vector<int>&dp){
    //     if(index<0) return 0;
    //     if(index==0) {
    //         if(!takeFirstElement){
    //             return nums[0];
    //         }
    //         return 0;
    //     }
    //     if(dp[index]!=-1) return dp[index];
    //     int take=nums[index];
    //     int notTake;
    //     if(index==nums.size()-1){
    //         take+=f2(true,index-2,nums,dp);
    //         notTake=f2(false,index-1,nums,dp);
    //     }
    //     else{
    //         take+=f2(takeFirstElement,index-2,nums,dp);
    //         notTake=f2(takeFirstElement,index-1,nums,dp);
    //     }
    //     // cout<<"At index"<<index<<"answer is"<<take<<" "<<notTake<<endl;
    //     return dp[index]=max(take,notTake);
    // }
    int rob(vector<int>&nums){
        return tabulation(nums);

    }
    
};