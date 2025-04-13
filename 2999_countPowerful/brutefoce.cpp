#include <string>
class Solution {
public:
    bool isValid(int currentNumber,int suffix,int limit){
        string number=to_string(currentNumber);
        string suff=to_string(suffix);
        if(!number.ends_with(suff)) return false;
        
        for(char ch:number)
        {
            int digit=ch-'0';
            if(digit<=limit) continue;
            else return false;
        }
        return true;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        if(stoi(s)>finish) return 0;
        if(stoi(s)==finish) return 1;
        // each digit should be at-most limit , but if limit<any of s then also return 0
        int count=0;
        // burteforce, checking each number
        int suffix=stoi(s);
        
        for(int i=start;i<=finish;i++)
        {
            // should be at-least suffix
            if(i<suffix) continue;
            if(isValid(i,suffix,limit)){
                cout<<"Integer"<<i<<endl;
                count++;
            }
        }
        return count;
    }
};