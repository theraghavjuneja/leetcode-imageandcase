### Since the constraints are very small I directly applied the bruteforce soln
- Okay still an explanation:
- number of pairs needed where both number in pair are equal and index multiply is divisible by k
- so i will traverse in O(n^2) and then try to satisfy the condn thats it
```cpp
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if((nums[i]==nums[j])&&((i*j)%k==0))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
```