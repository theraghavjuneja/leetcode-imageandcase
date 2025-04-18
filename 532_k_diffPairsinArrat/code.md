### 532 K Different Pairs in Array
#### Problem Statement
- Given are 2 things, an array nums & an integer k
- I need to return the number of unique k-diff pairs in array
### Ok so what are unique?
- lets imagine an array like [1,1,1,1,3,3,3,3] &k=2
- so answer here will be 1  (1,3) is the only combination. Irrespective of number of ones etc. Ignore that. (1,3) is the only combination so thus we only have one unique pair in the array
#### So first thing a person can think of while solving this is sorting & removing duplicates maybe using a set. But say I used a set and arr was [1,1] and k=0 . Answer should have been 1 and it came out 0 (due to set removed duplicates)
- So i think i cant use set, i should store some freuqency maybe a map. if k is 0 i will check curr frequency there or not?
- else I will check whether element+k or element-k exist. (check any one for each element of the array)
```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int cnt=0;
        unordered_map<int,int>frequency;
        for(int element:nums){
            frequency[element]++;
        }
        for(auto[element,occurence]:frequency){
            if((element+k)!=element){
                if(frequency.find(element+k)!=frequency.end()){
                    cnt++;
                }
            }
            else{
                // meaning if k==0
                if(occurence>1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
```