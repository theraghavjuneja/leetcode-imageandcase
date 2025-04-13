#include<iostream>
using namespace std;
// for large powers, this version crashes.
long long slowPower(long long base, long long exp){
    // we need to calculate base raise to power exp.
    // example 5 raise to power 3
    long long result=1;
    for(long long i=0;i<exp;i++){
        result=result*base;
    }
    return result;
}
// fast power
long long fastPower(long long base, long long exp){
    long long result=1;
    while(exp>0){
        if(exp%2==1){
            result=result*base;
        }
        base*=base;
        exp/=2;
    }
    return result;
}
int main()
{
    return 0;
}