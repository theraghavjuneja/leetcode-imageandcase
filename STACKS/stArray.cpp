#include<iostream>
using namespace std;
class Stack{
    public:
    int *arr;
    int size;
    int top;
    Stack(){
        arr=new int[1000];
        top=-1; //index
    }
    void push(int element){
        // cout<<"push called"<<endl;
        if(top<size-1){
            // cout<<top+1<<endl;
            top=top+1;
            arr[top]=element;
            return ;
        }
        else{
            cout<<"Stack  overflow";
        }
        return ;
    }
    
    int peek(){
        cout<<"Peek"<<endl;
        if(top>=0){
            return arr[top];
        }
        else {
            cout<<"Stack underflow";
            return -1;
        }
    }
    bool isEmpty(){
        // cout<<"emptu called"<<endl;
        if(top==-1){
            return true;
        }
        else return false;
    }
    void pop(){
        if(isEmpty()){
            return ;
        }
        top=top-1;
        // cout<<"Popped successfully";
        cout<<"Now value of top is"<<top<<endl;
        return ;
    }
    int getSize(){
        return top+1;
    }
    ~Stack(){
        delete [] arr;
    }
};
int main()
{
    // normal allocation
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}