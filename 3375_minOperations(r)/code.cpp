#include <iostream>
#include <vector>
#include<unordered_set>
using namespace std;
// i need to find min operations to make arr values equal to k
int minOperations(vector<int>&nums,int k)
{
    // i need to make all elements equal to k
    // at any step, choose an integer h,  h is valid if all values in arr > than h are equal
    unordered_set<int>mySet(nums.begin(),nums.end());
    int cnt=0;
    for(int val:mySet){
        if(val>k){
            cnt++;
        }
        if(val<k){
            return -1;
        }
    }
    return cnt;
}