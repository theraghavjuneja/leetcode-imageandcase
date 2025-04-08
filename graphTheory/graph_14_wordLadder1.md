### Word Ladder 1
- Okay so let me try to understand the question
#### It is saying I am given 
- a.) A start Word
- b.) An end word
- c.) A list representing words I can go
#### I need to go from start word to end word that's okay, using some steps in between which are in list. In short, I am on start word, Now I can try to change one letter of startWord and if i reach a word, which is in list , then i can take that step and so on...
#### How a graph question? It's easy to get intution of graph. Since we need to go from one place to other with some placeholders, that become something like directed graph. This is where I got intuiton
#### WHat I can think of
- I will push beginWord,1 in queue
- Then i will use unordered_set for visited
- Then i will pop front(), will check wordList, whether there exist a word where char difference is just one?
- If yes, then well & good, i will push that to queue and so on...
#### Okay so let's say there is something like (Edge case i thought of)
- hit,hot,dot,lot,log
(hit to log)
#### hit->hot->dot->lot->log
#### hit->hot->lot->log(a better path)
- how is this handled? okay so the distance we push to queue, automatically handles this. If distance wasnt pushed this was problematic...


#### this is the code first i wrote
```cpp
class Solution {
public:
    bool checkDifference(string a,string b)
    {
        int numberOfDifferences=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                numberOfDifferences++;
                if(numberOfDifferences>1) return false;
            }
        }
        if(numberOfDifferences==1) return true;
        return false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool isEndPresent=false;
        for(string element:wordList){
            if(endWord==element){
                // element found
                isEndPresent=true;
                break;
            }
        }
        if(!isEndPresent) return 0;
        // now the point is to make some sort of adj thing
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>visited;
        while(!q.empty()){
            auto[front,distance]=q.front();
            q.pop();
            for(int i=0;i<wordList.size();i++)
            {
                if(visited.find(wordList[i])==visited.end()){
                    if(checkDifference(front,wordList[i])){
                        // if this is true
                        int newD=distance+1;
                        q.push({wordList[i],newD});
                        visited.insert(wordList[i]);
                        if(wordList[i]==endWord){
                            return newD;
                        }
                    }
                }
            }


        }
        return 0;

    }
};
```

### but above code run-time is too high so I thought of a better approach. In above code for each word I am traversing wordList which is O(5000) for max 5000 word, what if i already store all words in some sort of set? That will give me O(1)? Isn't it. also i will pop elements from set as soon as i push to queue elinimating self-loops & also it would remove visited array as this set will only act as both visited as well as checker for new elem
```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>uset;
        bool found=false;
        for(string element:wordList){
            if(element==endWord) found=true;
            uset.insert(element); //Inserted
        }
        if(found==false) return 0;
        // unordered_set<string>visited;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        
        while(!q.empty()){
            auto[front,dist]=q.front();
            q.pop();
            for(int i=0;i<front.size();i++){
                char currentChar=front[i];
                // current string is front
                string currentString=front;
                for(char ch='a';ch<='z';ch++){
                    if(ch!=currentChar){
                        currentString[i]=ch;
                        if(uset.find(currentString)!=uset.end()){
                            // string found
                            q.push({currentString,dist+1});
                            if(currentString==endWord){
                                return dist+1;
                            }
                            uset.erase(currentString);
                        }
                    }
                }
            }
        }
        return 0;
        
    }
};
```


