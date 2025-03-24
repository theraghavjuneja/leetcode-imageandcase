### So question is saying  
- **Days** = Number of days  
- **Meetings** = Start & end days of meetings  

#### Example  
```cpp
meetings = [[5,7], [1,3], [9,10]]
```
That means he had meetings:  
- **Day 1 to Day 3**  
- **Day 5 to Day 7**  
- **Day 9 to Day 10**  

So, he was **free on Day 4 and Day 8**, making `count = 2`.

---

### Edge Cases  
1. If `start == end`  
2. If `last meeting end > new meeting start`  
   - Example: `[[1,3], [2,4]]`
3. If the **first meeting doesn’t start at Day 1**  
4. If the **last meeting doesn’t end at Day 'n'**  

---

### Intuition  
- Since the person **attends meetings in order**, we should **sort** the `meetings` vector.  
- After sorting, meetings will be ordered based on **start time**, and if start times are equal, then **end time**.  
- We need to find the intervals that are **not present** (i.e., the count of free days).  
- Consider a test case:  

```cpp
meetings = [[1,3], [5,7], [9,10]]
```
- What if we do `5 - 3 - 1`?  
  - This adds `1` to count → meaning **1 day was free**.  
- This suggests that we need to **subtract the current meeting start from the previous meeting end**.  

---

### Approach  
We declare two variables:  
```cpp
int prevEnd = 0;
long long int count = 0;
```
- `prevEnd`: Keeps track of the last occupied day.  
- `count`: Stores the count of free days.  

As we **iterate through meetings**, we update both.

---

### Handling Base Cases  

#### Case 1: `start == end`  
**Example:**  
```cpp
meetings = [[1,1], [4,4]]
days = 4
```
Expected Output: **2**  

- When `interval = [1,1]`, `prevEnd = 0`, so:  
  ```cpp
  count += 1 - 0 - 1 = 0;
  ```
- Now, `prevEnd = 1`.  
- When `interval = [4,4]`,  
  ```cpp
  count += 4 - 1 - 1 = 2;
  ```
  **Final count = 2**, so this works.

---

#### Case 2: Overlapping Meetings (`last meeting end > new meeting start`)  
**Example:**  
```cpp
meetings = [[1,5], [2,4], [6,9]]
```
- Our code will handle this since we update:  
  ```cpp
  prevEnd = max(prevEnd, end);
  ```

---

#### Case 3: If `days > prevEnd`  
- We **add `days - prevEnd`** to `count` to handle any remaining free days.

---

### Final Code  

```cpp
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int prevEnd = 0;
        long long int count = 0;

        for(int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];

            if(prevEnd < start) {
                count += start - prevEnd - 1;
            }
            prevEnd = max(prevEnd, end);
        }

        if(prevEnd != days) {
            return count + days - prevEnd;
        }
        return count;
    }
};
```
This efficiently finds the **number of free days** while handling all edge cases. 

