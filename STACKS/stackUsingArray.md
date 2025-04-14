## 📚 Stack Using an Array

A stack supports several core operations:
- `push`
- `pop`
- `top` (or `peek`)
- `isEmpty()`
- `size`

---

### 🛠️ Implementing a Stack with an Array

To implement a stack using an array, you'll typically need:
- An integer to track the `top` index.
- A normal or dynamic array to store the elements.
- A variable to define the `size` (capacity) of the stack.

You can initialize the stack in two ways:
1. Take the size as a parameter in the constructor.
2. Use a default constructor with a fixed large size.

Both approaches work fine, but note that in both cases, the stack has a fixed size.

Insertion (push) is based on the current value of `top`.

---

### 🔧 Stack Implementation Code

```cpp
using namespace std;
class Stack{
    public:
    int *arr;
    int size;
    int top;

    Stack(){
        arr = new int[1000];
        top = -1; // index
    }

    void push(int element){
        if(top < size - 1){
            top = top + 1;
            arr[top] = element;
            return;
        }
        else{
            cout << "Stack overflow";
        }
        return;
    }

    int peek(){
        cout << "Peek" << endl;
        if(top >= 0){
            return arr[top];
        }
        else {
            cout << "Stack underflow";
            return -1;
        }
    }

    bool isEmpty(){
        return top == -1;
    }

    void pop(){
        if(isEmpty()){
            return;
        }
        top = top - 1;
        cout << "Now value of top is " << top << endl;
        return;
    }

    int getSize(){
        return top + 1;
    }

    ~Stack(){
        delete [] arr;
    }
};
```

---

### 🔍 Notes on Dynamic Array Declaration

To create a dynamic array in C++:
```cpp
int *arr = new int[capacity];
```

Here, `int *arr` points to the first element of the dynamic array.

To check the size, you can use:
```cpp
sizeof(arr);
```

Keep in mind this returns the size of the pointer, not the allocated array size.(as remember arr is actually a pointer to arr[0]);

#### Another Note
- Maybe I could have also used something like int *arr=new int[500]; just while declaration
