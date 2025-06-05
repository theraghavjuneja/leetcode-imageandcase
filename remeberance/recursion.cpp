#include<iostream>
#include<vector>
using namespace std;
// for a k length string, it will calculate all possible sums
void allPossibleSums(int index,vector<int>&array,int k,int currentSum,vector<int>&answer){
    if(k==0){
        answer.push_back(currentSum);
        return ;
    }
    if(index<0||k>index+1) return ;
    allPossibleSums(index-1,array,k-1,currentSum+array[index],answer);
    allPossibleSums(index-1,array,k,currentSum,answer);
}
int main()
{
    return 0;
}