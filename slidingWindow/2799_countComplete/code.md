## Count Complete SubArrays in an Array
### Problem Definition:
- A complete subarray: Number of distinct elements in subarray equals number of distinct elements in whole arrays.
#### Intuition/ Thinking
- First of all I will start with O(n^2) solution
- So what I need is I anyhow needs to count no of distinct elements in whole array(unordered_set can be used)
- Then for each subarray I need to count whether number of elements is equal to number of elements in whole array.
- Again, I can use one more unordered_set here, and whenever the elements become equal I will add +=1
#### O(n^2) and O(n) (Time & Space) Soln
```cpp
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans=0;
        unordered_set<int>numberOfDistinctElements;
        for(int element:nums){
            numberOfDistinctElements.insert(element); // to count number of distinct elements in whole array
        }
        int totalDistinctElements=numberOfDistinctElements.size();
        for(int i=0;i<nums.size();i++){
            // to count number of distinct elements in currentsubarray
            unordered_set<int>currentCount;
            for(int j=i;j<nums.size();j++){
                currentCount.insert(nums[j]);
                //even if currentCount becomes equal to totalDistinct I should keep adding as say [1,3,2,1] is complete subarray. Then [1,3,2,1,2] will also be (i.e. elements after rightmost)
                if(currentCount.size()==totalDistinctElements){
                    ans++;
                }

            }
        }
        return ans;
    }
};
```

#### Okay so this was O(n^2) solution. Now for O(n). O(n) even took me 1 hour to right
### O(n) solution
#### Intuition and Thinking
- Imagine an array like [999,1000,999,1000,999]
- Now first complete subarray is [999,1000]. And there are a total of 4 complete subarray starting from first 999.
- i.e. nums size-rightmost index of that subarray = no of complete subarrays starting from any index i
- in short, for each i need to find one sub-array. then I can just do nums.size()-rightMostIndex..

### So imagine arr like [1,3,1,2,2]
- left=0,right=0
- i will keep on increasing right pointer till I encounter my first subarray
- so left=0, right=3, (here is my first subarray)
- i will track count 1:2, 2:1, 3:1 (how many times each element appears)
- Now i will check how many elements exist to right of right pointer it's 1 element. so starting from left=0, I can get 2 subarrays 1,3,1,2 and 1,3,1,2,2
- Now its turn to move left Pointer
- so say leftElement=1(index 0), move leftPointer 1 step forward, so left=1
- now decrease leftElement from the frequency. SO frequency is 1:1,2:1,3:1 . Still all elements are there, i will again add nums.size()-right to the answer to encounter all arrays starting from left
- Now i will move left to 2. but this time when I do freqncy becomes 1:1,2:1,3:0. So that means this is not a complete sub-array. so i will break left loop. Remove 3 from frequency
- and will continue this game
```cpp
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
```