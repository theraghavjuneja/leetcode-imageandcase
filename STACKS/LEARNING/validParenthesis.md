## 20 Valid Parenthesis
### Problem Statement
#### Given- a string s, and characters '(', ')', '{', '}', '[' and '], we need to determine if valid
- when it will be valid?

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
#### Okay so for these prblems where we need to maintain a strict order, we generally prefer stack
- We will be pushing opening brackets in stack and each time a closing will come I will check whether st top==closing. if yes pop else return false
- at end after all string has been processed if stack become empty return true else return false

### Solution O(n) time&space
```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        // should only push open brackets to stack
        for(char ch:s){
            if(ch=='('||ch=='['||ch=='{'){
                st.push(ch);
            }
            else{
                if((ch==')'&&!st.empty()&&st.top()=='(')||(ch==']'&&!st.empty()&&st.top()=='[')||(ch=='}'&&!st.empty()&&st.top()=='{')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};
```