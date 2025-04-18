## STACKS
- Last In First Out
- push, pop,top, isEmpty(),size are the operations supported
#### Okay so how do we create stacks ourselves?
- so first method is ofcourse using an array, so what we can essentially do is create a array of some large size say 1000, and declare top=-1, and some size=1000, and then perform methods on array. Bad thing about this is cant go beyond that large size.
- Remember arr created using int *arr=new int[1000]; Even dynamic array are created this way. If i just use int *arr , that means a single pointer and even after arr=new int[1000]; arr is somethign that now points to first element of the array
- Also, we can use dynamic memory here, like initially creating arr size=2, then if arr is full and we are trying to insert then double the size, create new array,push from old to new, delete old, again do old=new thats it
- Now what about linked-list?
- If we use linked list, we just need to declare a top pointer, also say we push 10,20,30 then mapping should be like 30->20->10 opposite way so that if top is deleted it can reach to next top which is 20