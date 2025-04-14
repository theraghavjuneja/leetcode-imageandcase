#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};
class Stack{
    public:
    Node *topNode; //and not int* topNode
    Stack(){
        topNode=NULL;
    }
    void push(int element){
        if(topNode==NULL){
            topNode=new Node(element);
            topNode->next=NULL;
            return ;
        }
        Node* node=new Node(element);
        node->next=topNode; //i will set next of node to topnode
        // meaninf say already 10 is there, now i insert 20 i will set 20->10
        // and so on and will do topNode=no
        topNode=node; 
        
    }
    void pop(){
        if(topNode==NULL){
            cout<<"Already empty"<<endl;
            return ;
        }
        else{
            Node* temp=topNode;
            topNode=topNode->next;
            delete temp;
        }
    }
    bool isEmpty(){
        if(topNode==NULL){
            return true;
        }
        return false;
    }
    int top(){
        if(topNode!=NULL){
            return topNode->data;
        }
        else return -1;
    }
    int size() {
        int count = 0;
        Node* temp = topNode;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }


};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.isEmpty()<<endl;
    s.push(90);
    cout<<s.top()<<endl;
    return 0;
}