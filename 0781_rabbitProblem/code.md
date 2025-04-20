##  Rabbit Grouping Problem

###  Explanation

- Remember, **not all rabbits in the forest are answering**.
- The **minimum number of rabbits** is **not necessarily `n`** (the number of answers).
- The question appears straightforward, but it's a little bit tricky.

---

###  Hint

- Handle `0` **differently** from other elements.
- For other elements:
  1. Assume the array is:  
     `[2, 1, 2, 2, 2, 2, 2, 2, 1, 1]`
  2. Count the occurrences:
     - `2` occurs **7 times**
     - `1` occurs **3 times**
  3. Use a **grouping factor** defined as `element + 1`.

####  Example Calculation

- For `2`:
  - Grouping factor = `2 + 1 = 3`
  - Group into sets of 3: `(2,2,2)(2,2,2)(2)`
  - So we need **3 groups** ⇒ Answer = `3 * 3 = 9`

- For `1`:
  - Grouping factor = `1 + 1 = 2`
  - Group into sets of 2: `(1,1)(1)`
  - So we need **2 groups** ⇒ Answer = `2 * 2 = 4`

---

###  Final Answer

Total minimum number of rabbits = `9 (for 2s) + 4 (for 1s) = 13`


```cpp
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>freqCount;
        int cnt=0;
        for(int element:answers){
            freqCount[element]++;
        }
        for(auto [element,count]:freqCount){
            if(element==0){
                cnt+=count;
                continue;
            }
            // say 2 occurs 7 times 1 occur 3 times
            // (2,2,2)(2,2,2)(2) (1,1) (1) Total 3+3+3+2+2 i.e. 3*3+2*2
            int effect=element+1; //this is the grouping factor
            int division=count/effect;
            int remainder=count%effect;
            cnt+=(division*effect);
            if(remainder!=0){
                cnt+=effect;
            }
        }
        return cnt;
    }
};
```