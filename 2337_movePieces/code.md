## 2337 Move Pieces to obtain A String
- a lot of if-else & edge cases
## left count-
- if start is blank and target='L' then it's a leftCount, (it need to be balanced)
- if start is 'R' and target ='_' then it's a right Count, need to be balanced
- if any count get<0 return false
- if we are decreasing rc/lc but there are unbalanced opposite count return false
- if at end both count=0 return true
```cpp
class Solution {
public:
    bool canChange(string start, string target) {

        int leftCount=0,rightCount=0;
        for(int i=0;i<start.size();i++){
            char startCharacter=start[i];
            char targetCharacter=target[i];
            if(startCharacter==targetCharacter=='_') continue;
            if(startCharacter=='_'){
                if(targetCharacter=='L'){
                    leftCount++;
                }
                else if(targetCharacter=='R'){
                    if(leftCount>0) return false;
                    rightCount--;
                    if(rightCount<0){
                        // cout<<"c2"<<endl;
                        return false;
                    }
                }
            }
            if(startCharacter=='L'){
                if(targetCharacter=='_'){
                    if(rightCount>0) return false;
                    leftCount--;
                    if(leftCount<0){
                        // cout<<"C3"<<endl;
                        return false;
                    }
                }
                if(targetCharacter=='R'){
                    // cout<<"c4"<<endl;
                    return false;
                }
                if(targetCharacter=='L'){
                    if(rightCount>0) return false;
                    else continue;
                }
            }
            if(startCharacter=='R'){
                if(targetCharacter=='_'){
                    rightCount++;
                }
                else if(targetCharacter=='L'){
                    // cout<<"c5"<<endl;
                    return false;
                }
                else if(targetCharacter=='R'){
                    if(leftCount>0) return false;
                    else continue;
                }
            }

        }
        if(leftCount==0&&rightCount==0) return true;
        else return false;
    }
};
```