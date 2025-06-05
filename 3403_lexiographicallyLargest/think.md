#### Question is stating
1. Given a string, I will split up into numFriends number of strings.
2. Example numStrings=2 then a string like "abcdzeklm" can be splitted into 2 parts a|bcd... ab| cd... etc.
- Now i need to find lexiographically largest string 
- okay so splitting etc. rounds, no prev rounds are confusing things just

### Question simply wants to say Split a string into numFriends strings ( each way you can) and among it find largest string (alphabetically)
#### Now what is a lexiographically larget string?
```cpp
bool whichLarger(string a,string b){
    return a>b; // if string a is larger it will return true else false as simple as that (Lexiographic)
}

```

### So how do we solve? Let me think of various things

- I will take this string abcdzeklm
- Now say numStrings=2 , I can split it like a, bcd... ab, cd.. or abc,dze... . But among it lexiographically larger will be zeklm 
- One thing is clear, a lexiographial larger string (or alphabetical larger) will always start from largest character.
### SO this is step one (It always start from largest character). Thus find largest character

### Now "abcdzeklm"
1. When numFriends=1 answer=abcdzeklm (Base)
2. When numFriends=2 answer=zeklm (abcd,zeklm)
3. When numFriends=3 answer=zeklm (ab,cd,zeklm)
4. When numFriends=4 answer=zeklm (a,bc,d, zeklm)
5. When numFrinds=5 answer=zeklm(a,b,c,d,zeklm)
6. i.e. answer will be str.substr(indexOfLargestCharacter, end of string) if numFriends<=indexofLargestCharacter+1

7. when numFriends=6 , answer =zekl(a,b,c,d,zekl,m)
8. when numFriends=7 , answer=zek(a,b,c,d,zek,l,m)
- i.e. initially i try to remove from start (All of it i will remove if numFriends<=index+1) . then i will remove from end one by one got it?
### this whole can be coded as (A representation)
```cpp
char findLargestCharacter(){
    // code to find largest character
    return largestCharacter;
}
char lc=findLargestCharacter...(string)
for(int i=0;i<n;i++){
    numFriends--; //decrease numFriends
    
    if(n[i]==lc){
        // meaning current char is largest (like 'z' in prev example)
        if(numFriends<0 ) // this means that if numFriends<=indexofLargestCharacter+1 (Since we did numFriends-- so new condition){
            return word.substr(i) // start to end
        }
        else{
            return word.substr(i,word.size()-i-numFriends)
        }
    }

}
```
### Now there is a problem what if z occured twice? 
- say abcdzeklmzy
### Now our above code will fail here, as it will return zek.. (but) answer is zy
- so we need to tackle this.
1. In prev code, we are early returning
2. Now we wont return early, we will store each ans (starting from largestCharacter) and if currentAnswer> new replace

```cpp
class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
        char largestCharacter=word[0];
        for(int i=0;i<word.size();i++){
            if(word[i]>largestCharacter){
                largestCharacter=word[i];
            }
        }
        // now there can be more than one instance of largest character
        string ans="";
        for(int i=0;i<word.size();i++){
            numFriends--; // each index= one numFriend
            if(word[i]==largestCharacter){
                string cur="";
                if(numFriends<0){
                    cur=word.substr(i); // encounter initial ones
                }
                else{
                    cur=word.substr(i,word.size()-i-numFriends);
                }
                if(ans<cur) ans=cur; //to encounter multiple times one char appear
            }

        }
        return ans;
        

    }
};
```