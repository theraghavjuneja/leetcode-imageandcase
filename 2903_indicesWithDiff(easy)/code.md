### 2903 Indices with difference
- Since the constraints are very small a bruteforce would work
```cpp

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int>answer={-1,-1};
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                if((abs(i - j) >= indexDifference)&&(abs(nums[i] - nums[j]) >= valueDifference)){
                    answer[0]=i;
                    answer[1]=j;
                    return answer;
                }
            }
        }
        return answer;
    }
};

```