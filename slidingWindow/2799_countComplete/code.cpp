
#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans=0;
        unordered_set<int>numberOfDistinctElements;
        for(int element:nums){
            numberOfDistinctElements.insert(element);
        }
        int totalDistinctElements=numberOfDistinctElements.size();
        int left=0;
        int right=0;
        unordered_map<int,int>frequency;
        while(right<nums.size()&&left<nums.size()){
            // cout<<"Left and right are"<<left<<"  "<<right<<endl;
            frequency[nums[right]]++;
            if(frequency.size()==totalDistinctElements){
                // cout<<"right is"<<right<<endl;
                int totalSubArraysToBeAdded=nums.size()-right;
                // cout<<"Adding"<<totalSubArraysToBeAdded<<endl;
                ans+=totalSubArraysToBeAdded;
                while(true){
                    int leftElement=nums[left];
                    left++;
                    frequency[leftElement]--;
                    if(frequency[leftElement]!=0){
                        // cout<<"inside adding"<<nums.size()-right<<endl;
                        ans+=nums.size()-right;
                    }
                    else{
                        frequency.erase(leftElement);
                        break;
                    }
                }
            }
            right++;
        }

        return ans;
    }
};