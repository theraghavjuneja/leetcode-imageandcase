#### 2905 Find Indices With Index & Value Difference 2
##### Note: Todo https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/ before doing this. 
- Both problems have same concept of going k steps backward and satisfying condn given. This one is solved using modified sliding window/2 pointer, and that one using set.
#### Problem Statement
- Ok so we need to find 2 indices i&j such that abs|i-j|>=indexDifference & abs|nums[i]-nums[j]|>=valueDifference. Now there maybe many indices I just need to return one of them. If no index exist return {-1,-1}.
- Okay so before jumping to soln, i would like to remember myself or someone reading that I spent over 1-2 hours in this problem or more. So, i tried sets, maps, normal sliding window, sorting, heaps, lower, upper bound etc. I was unable to form a direct soln using any of them . (a soln maybe exists in them, in O(nlogn)). But I was unable to crack that.
- So , let me just start with Intution
### Intuition

- lets imagine an array like 5,3,4,6,6,6,1 Okay perfect!
- Now, say valueDifference=4 and indexDifference maybe say 2.
- Say I start from 5, say first number=5, now what all can be second number. It can be 4,6, or 1 right? Since, they are>=2 indexes apart. Similarly say first number=1, second can be 5,3,4,6(except last 6). Perfect!
- Now for any element say 6, there will always be a set of elements on left and one on right? (for right, I can have 1. For left I can have 5 or 3 or 4, depending upon which 6 I took)? Yes
- But I cant go both directions. So for each element I will be seeing the elements only in one direction . I will be seeing in left okay? You can also see in right (if you choose not to see on left)
- So let's start
- at i=0, element=5, but 2 indices to left, there is nothing
- at i=1, element=3 but 2 indices to left, there is nothing
- at i=2, element=4, 2 indices to left I only have 5? okay?
- (5,3,4,6,6,6,1)
- at i=3, element=6, 2 indices to left I have 5 &3,
- at i=4, element=6, 2 indieces to left, I have 5,3,4
- and so on
- at i=6, element=1, 2 indices to left I have 5,3,4,6 right?

- Now there will be a number of elements on left? Yes! If i just traverse all these elements again and again, it will become a O(n^2) solution.
- so what can I do?
- for each element I need to just make sure that abs|nums[i]-nums[j]|>=valueDifference. First condn is always satisifes of indexDifference (as i am only looking at those elements). 
- say i=6, elements on left were 5,3,4,6 right?
- Now what all elements satisfy condition they are 5&6, right (i.e. the elements with most difference from 1).
- Imagine set of 10 elements, Now from any one element which will be the most farthest? the one which will be max/min right?
- so what If i just tracked max & min element, since if any other element satisfy, this will also satisfy (any one or both of them). and we just need one answer. so i will just track min & max element at atleast indexDifference left places. This forms the base of answer
- I will keep on updating and adding one new element 
### Now i think anyone can code. here is the code
```cpp
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int maxElement=INT_MIN;
        int minElement=INT_MAX;
        int maxIndex=-1;
        int minIndex=-1;
        // now from range 0->index difference i have max & min
        // ques-> why max & min. See we only need to find one pair, and not all or not one with a constraint. Since it's one pair
        // it will be quite easy to find if i track max & min . Since if i get no>max then most far number=min . nd if i get no<min then most far number=max, indexDifference is already maintained 
        // and also if number lies between them, then most far number will be either max/min. If they only doesnt lie in valueDifference- then no one can lie
        for(int i=indexDifference;i<nums.size();i++){
            int elementBeforeIndexDifference=nums[i-indexDifference];
            if(elementBeforeIndexDifference>maxElement){
                maxElement=elementBeforeIndexDifference;
                maxIndex=i-indexDifference;
            }
            if(elementBeforeIndexDifference<minElement){
                minElement=elementBeforeIndexDifference;
                minIndex=i-indexDifference;
            }
            // now at this time i will always have track of max& min element before index difference
            if(abs(nums[i]-minElement)>=valueDifference) return {minIndex,i};
            if(abs(nums[i]-maxElement)>=valueDifference) return {maxIndex,i};

        }
        return {-1,-1};
        // ALWAYS I AM TRACKING MIN & MAX BEFORE indexDifference places. This will help us to give one answer always
    }
};
```

### Clean code without comments
```cpp
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int maxElement=INT_MIN;
        int minElement=INT_MAX;
        int maxIndex=-1;
        int minIndex=-1;
        for(int i=indexDifference;i<nums.size();i++){
            int elementBeforeIndexDifference=nums[i-indexDifference];
            if(elementBeforeIndexDifference>maxElement){
                maxElement=elementBeforeIndexDifference;
                maxIndex=i-indexDifference;
            }
            if(elementBeforeIndexDifference<minElement){
                minElement=elementBeforeIndexDifference;
                minIndex=i-indexDifference;
            }
            if(abs(nums[i]-minElement)>=valueDifference) return {minIndex,i};
            if(abs(nums[i]-maxElement)>=valueDifference) return {maxIndex,i};

        }
        return {-1,-1};
       
    }
};```