#### Okay so this is a cost (min cost) based problem
##### If you are new to these kind of problems one thing to remember
- If you get out of the bounds return 1e9 to emphasisze this is a very high cost
- else return the min of all paths available to you....
- this is all we need to do

#### Okay so problem explanation
- Imagine we are travelling in array. We can start from index 0 or index 1. Now at each instance i can jump 1 or 2 step. But before jumping i need to pay cost equavilane to the cost[i]. then i can jump either 1 or 2 steps that depend on me. 
- okay so let's say that I consider the given array
##### [10,15,20]. Now let's start with 10 <br>
<>
#### Okay so i am at 10. I can jump to 15 or 20. (cost +10)
#### Now say I went to 15. I can jump to 20 or out of array. Say i went to 20(cost+15)
#### I am at 20. Now I can jump to out of array(cost+20)
- so total cost if i go 10->15->20= 45
- i can also go like 10-
