### This question has same code as 2337 Move Pieces (Only difference- "X" instead of "_"). rest all is same
```cpp
class Solution {
public:
    bool canTransform(string start, string result) {
        // IT IS SAME AS PREV ONE 
        int leftCount=0,rightCount=0;
        for(int i=0;i<start.size();i++){
            char startCharacter=start[i];
            char targetCharacter=result[i];
            if(startCharacter==targetCharacter=='X') continue;
            if(startCharacter=='X'){
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
                if(targetCharacter=='X'){
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
                if(targetCharacter=='X'){
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