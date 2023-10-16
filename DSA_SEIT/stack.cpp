#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
    node(int val){
        data = val;
        next = NULL;
    }
};

class stack1{
    node *top;
    public:
    stack1(){
        top = NULL;
    }
    bool isEmpty(){
        return top==NULL;
    }
    void push(int val){
        node *tmp = new node(val);
        if(top==NULL){
            temp->next = NULL;
        }
        else{
            tmp->next = top;
        }
        top = tmp;
    }
    void pop(){ 
        if(isEmpty())
        {
            cout << "Stack Underflow\n";
        }
        else
        {
            node *tmp = top;
            cout << tmp->data << " deleted from top successfully \n";
            top = top->next;
            delete tmp;
        }
    }
    void display(){
        node *ptr = top;
        if(isEmpty())
        {
            cout << "Stack is Empty\n";
        }
        else
        {
            while( ptr != NULL )
            {
                cout << ptr->data << ' ';
                ptr = ptr->next;
            }
            cout << ptr->data << endl;
        }
    }
};

void menu()
{
    cout << "Enter 1 To Push Data. \n";
    cout << "Enter 2 To Pop Data\n";
    cout << "Enter 3 to Display data\n";
    cout << "Enter 0 To Exit \n";
}

int main()
{
    stack1 stk;
    int choice = 1, val;
    menu();
    do
    {
        cout << "Enter your Choice :";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter the Value: ";
                cin >> val;
                stk.push(val);
                break;
            case 2:
                stk.pop();
                break;
            case 3:
                stk.display();
                break;
            default:
                cout << "!! Enter Valid Value :";
        }
    }
    while(choice);
    return 0;
}