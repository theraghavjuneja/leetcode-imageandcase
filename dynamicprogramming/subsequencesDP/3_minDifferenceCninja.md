### Here
- n positive integers.
- Partition into 2 subsets such that absolute difference between both of them is minimal
- So, imagine sum=6
- i can be like a+b=6, then :
```
a=0,b=6  a=6,b=0
a=1,b=5  a=5,b=1
a=2,b=4  a=4,b=2
a=3,b=3  a=3,b=3
```
- say i took only first (left) side as right side is same if a+b=sum, then b+a=sum(associative property, bro!)
- so for a+b? i will check whether target a can be achieved. If yes then ofcourse'b' can also be so that makes sense. then on basis of these 2 i will update minDifference bro! something like minDifference=min(minDifference, abs(a-b)). Thats it it is done now, 