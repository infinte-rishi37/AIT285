#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

class stack1
{
    node *top = NULL;
    node *push(int val, node *top)
    {
        node *ptr, *tmp=top;
        ptr = new node;
        tmp->data = val;
        tmp->next = top;
        top = tmp;
        return top;
    }
    node *pop(node *top)
    {
        if(top == NULL)
        {
            cout << "The Stack is Empty, No deletion can be performed.\n";
        }
        else
        {
            node *tmp = top;
            top = top->next;
            delete(tmp);
        }
        return top;
    }
    void display(node *top)
    {
        node *ptr = top;
        if(ptr == NULL)
        {
            cout << "Stack is Empty\n";
        }
        else
        {
            while(ptr->next!=NULL)
            {
                cout << ptr->data << ' ';
            }
            cout << ptr->data << endl;
        }
    }
};


void menu()
{
    cout << "Enter 1 To Push Data. \n";
    cout << "Enter 2 To Pop Data\n";
    cout << "Enter 0 To Exit \n";
}

signed main()
{
    stack1 stk;
    stk.top = NULL;
    int choice = 1, val;
    do 
    {
        menu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter the Value: ";
                cin >> val;
                top = stack1.push(val, stk.top);
                break;
            case 2:
                stack1.pop(stk.top);
                break;
            default:
                cout << "Enter Valid Value.\n";
        }
    }
    while(choice)
}