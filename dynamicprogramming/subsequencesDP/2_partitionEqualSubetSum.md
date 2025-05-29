### Okay so
1. Given an array nums, partition it into subsets such that sum of elements in each of them is equal
2. Say subsets sum are a+b , so a+b=total Sum .
3. a=b, so 2a=total thus a=total/2
4. I need to check , whether a subset exists whose sum is total/2, Yes or NO?
5. Edge Case: Is total/2 valid? what if total is odd(Problem hai yeh!!). if total is odd, it is clearly not possible so whan return false
6. else follow code for subset sum equal to k got it?