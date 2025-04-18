### 38 Count and Say
#### Problem Definition
- What's Count And Say. It 's just a recursive formula based on
- countAndSay(1)="1"
- countAndSay(n)=RLE of countAndSay(n-1)
- Example n=4
- so n=4-> RLE(n=3)-> RLE(n=2)->RLE(n=1) For n=1 the value is "1"
- so 1 is passed to n=2. Now for this it becomes "11". Now "11" is passed to n=3 so it will become "21". Now "21" gets passed it will become "1211". 
- Rle is just(example 33) RLE=23 ( as 3 occur 2 times). So its occurence followed by kiski

- Now lets look at next thing it is the constraints
- So constraints are n=30 tak
- So I can easily use a Recursive soln. Based on n<=30, both recursion & DP will have equal performance I guess

#### Now how will recursion solution look like?
- For n=1 return "1"
- else do some computation for n-1
- What is that computation? Take previous recursion answer. Traverse and then return character followed by count

#### This is how soln will look like
```cpp
class Solution {
public:
    string recursionSolution(int n){
        if(n==1) return "1";
        string previousAnswer=recursionSolution(n-1);
        // cout<<"prev answer"<<previousAnswer<<endl;
        if(previousAnswer=="1") return "11";
        int prevCount=1;
        // now number of chars will always be greater than 1
        char repeatingCharacter=previousAnswer[0];
        string answer="";
        for(int i=1;i<previousAnswer.size();i++){
            char current=previousAnswer[i];
            if(current==repeatingCharacter){
                prevCount++;
            }
            else{
                answer.push_back(prevCount+'0');
                answer.push_back(repeatingCharacter);
                repeatingCharacter=current;
                prevCount=1;
            }
        }
        answer.push_back(prevCount+'0');
        answer.push_back(repeatingCharacter);
        return answer;

    }
    string countAndSay(int n) {
        return recursionSolution(n);
    }
};
```