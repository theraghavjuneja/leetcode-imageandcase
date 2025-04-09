## 3375 Daily problem 09 April
#### First of all, what is valid h?  a integer in which vall values in array strictly greater than h are same. Example [5,3,5,4,5] valid h=4 (as all elements > than 4 are same i.e. 5)
#### Okay so the problem statement was a bit unclear. Here is what we need to do. Assume i have an array now in this array i nee dto perform some operations. in each operation, i can select any integer h which is valid, and then for all elements> h i can set nums[i] to h.

#### Example [5,2,5,4,5] Initially h=4, now arr becomes [4,2,4,4,4] then h=2, arr becomes[2,2,2,2,2] now that's it op=2
#### Example [2,1,2] k=2 Here, since one value 1<2 , I cant make all values equal to 2

So we got our base case. if one value <k then we should return -1;
#### Intituion: what i see is , whichever value is maximum.just find 2nd maximum and convert all maximum to second maximum and so on till all values =to k. Now instead of comverting can't i count?? Say i use an unordered_set and in that set I can just store all elements. 
#### Example [5,2,5,4,5] will become [2,4,5] now there are 2 elements> than k so first time k=4 then k=2. so answer= no of elements> than k. if any element is lesser return -1
```cpp
class Solution {
public:
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
};
```