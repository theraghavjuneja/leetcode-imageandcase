### Stack using an Array
- Okay, so let me try to recall what all operations does a stack support
- They were top, push, pop, isEmpty(),size etc.
##### So I need to declare a stack using array. So what all things will I need  ? Maybe I need to track top, I will need a normal or a dynamic array, and something like size.
##### What if initially I take size in constructor? It can be done too. There is also another approach where you declare an empty constructor, with a large size maybe that can also be done too. So both approaches are good, but they will always store a fixed size. And yeah based on top we can insert values. 
#### Code is quite simple
```cpp
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
```

#### Okay so another thing a dynamic array is also created by int *arr=new int[capacity]
#### int *arr(pointer to single int (or start of dynamic array))
##### For creation, int *arr=new int[size];
##### sizeof(arr) to find size