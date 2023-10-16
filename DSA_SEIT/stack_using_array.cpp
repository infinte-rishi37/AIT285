#include <bits/stdc++.h>
using namespace std;

const int SIZE=5;
int top = -1;
int stack1[SIZE];

bool isEmpty()
{
    return top == -1;
}

bool isFull()
{
    return top == SIZE-1;
}

void push()
{
    if(isFull())
    {
        cout << "Stack OverFlow\n" ;
    }
    else
    {
        int val; 
        cout<< "Enter value to be pushed into stack1 :";
        cin >> val; 
        stack1[top]=val;
        top++;
    }
}

void pop()
{
    if(isEmpty())
    {
        cout << "Stack UnderFlow\n" ;
    }
    else
    {
        cout << "The top value " << stack1[top] << "is removed\n";
        stack1[top]=-1;
        top--;
    }
}

void peek()
{
    if(isEmpty())
    {
        cout << "Stack is Empty\n";
    }
    else
    {
        cout << stack1[top] << " <- Element at top\n";
    }
}

void display()
{
    if(isEmpty())
    {
        cout << "Stack is Empty\n";
    }
    else
    {
        for(int i=top;i>-1;i--)
        {
            cout << stack1[i] << ' ';
        }
        cout << endl;
    }
}

signed main()
{
    int choice = 1;
    cout << "Enter 1 to push data into stack1\n";
    cout << "Enter 2 to pop data from stack1\n";
    cout << "Enter 3 to Peek \n";
    cout << "Enter 4 to display data\n";
    cout << "Enter 0 to Stop\n";
    do
    {
        cout << "Enter Your choice  : ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3;
                peek();
                break;
            case 4:
            if(isEmpty())
                display();
                break;
            default:
                cout << "INVALID VALUE:  Enter again :";
        }
    } 
    while (choice);
}