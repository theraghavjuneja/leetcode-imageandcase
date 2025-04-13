### 1922 Count Good Numbers
#### Okay so let's understand requirements of question
#### When is a digit string good?
- if digits are even indices are even & odd indices are prime okay got it.?
- Example, 2582 (0,1,2,3,) At index 0->2 (good) At index 1(5)-> prime At index 2-> 8(even), At inex 3->3(prime)

#### let me try to form a relation, essentially it seems like a permutation problem to me..
- When n=1, we can have a string of length 2 which can have 0,2,4,6,8 So ans=5
- When n=2, we can a string of length 2 indices 0,1 so at index 0 I can have 0,2,4,6,8 and at index 1-> 1,3,5,7 Essentially that makes a total of 5*4=20 ways
- When n=3, we can have indices 0,1,2 . For 0 & 2 no of ways =5 each. For 1, no of ways=4 5*5*4=100 Ways 
- and so on

##### This is how we formed a relation, what we can do is declare a count and loop from 0 to n. If current i is odd multiply by 4 else multiply by 5.
##### **PROBEM** THE INTEGER OVERFLOW. Even at n=50, it will do some integer overflow, since at each point we are multiplying odd even etc.
##### But let's think of final result . It's 5 raise evenCount *4 raise oddCount
###### Now let's think of other way? What if we count no of even indices, no of odd indices . Example in n=3, even indices=2, odd indices=1. and then calculate even power and odd power separately. Assume case of n=3 only . In even indices we have index 0&2. We evenCount=2, and power will become 5 raise to power 2=25. for oddCount=1, power =4. Ans=25*4. (we will apply mod etc.)
```cpp
class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2; //calculate even indices
        long long oddCount = n / 2; //odd indices
        long long evenPow = modPow(5, evenCount, MOD); //say even indices=2, it calculate 5 raise to power 2
        long long oddPow = modPow(4, oddCount, MOD); //say odd indices=1, it caculate 4 raise to power 1 then
        return (evenPow * oddPow) % MOD;
    }
};

```