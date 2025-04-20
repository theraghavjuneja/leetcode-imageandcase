### 1003 Valid Words
- Okay so given a string, I need to determine valid or bit
- A string s ->valid , if I start from empty string, and I can insert abc at any position. Got it
- So given a string I need to tell if it's valid or not
### Ituition
- Consider s="aabcbc" . Okay so say t="" I inserted abc so t="abc" then I inserted abc again after a, so it become aabcbc. So this s is valid
- But, we need to traverse/do this in opposite direction. 
aabcbc->
- I see 'a' Okay good store it somewhere
- then i again see 'a' okay good store it as some other entry
- Now I see 'b' , I check last entry it was 'a'. So append b to last entry
- Now I have 'c' . I see last entry was 'ab' so append 'c' . i got 'abc' I can pop it now, as it became a sequence meaning abc was inserted here
- Then now I see 'b' again, so prev entry now is 'a'. (first entry).
- then again 'c' so prev entry first a+ this b='ab' so remove whole 'abc' now,
- now nothing, so return true , else false
### See this above gave us intituion of stack, like at any time I can assume any element to be top, and when that element is whole completed as "abc" i can pop it
```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<string> st;
        for (char ch : s) {
            if (ch == 'a') {
                st.push("a");
            } else if (ch == 'b') {
                if (!st.empty() && st.top() == "a") {
                    st.pop();
                    st.push("ab");
                } else {
                    return false;
                }
            } else if (ch == 'c') {
                if (!st.empty() && st.top() == "ab") {
                    st.pop();
                    // completed "abc", nothing to push
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

```