#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int val){
        data = val;
        next = NULL;
    }
};

map<char,int> pres = {{'/', 5}, {'*', 4}, {'+', 3}, {'-', 2}, {'(', 0}};

class Stack{
    node *Top;

    public:

    Stack(){
        Top==NULL;
    }

    bool is_empty(){
        return Top==NULL;
    }

    void push(int val){
        node *tmp = new node(val);
        if(is_empty()){
            Top = tmp;
        }
        else{
            tmp->next = Top;
            Top = tmp;
        }
    }

    int top(){
        if(is_empty()){
            cout << "Stack Empty\n";
        }
        else{
            return Top->data;
        }
        return 0;
    }

    void pop(){
        node *tmp = Top;
        if(is_empty()){
            cout << "Stack Underflow\n";
        }
        else{
            Top = Top->next;
            free(tmp);
            cout << "\nPopped " << tmp->data << " from the top of Stack" ;
        }
    }
};

string infixToPostfix(string infix){
    string postfix="";
    Stack st = Stack();
    for(auto& i: infix){
        if(i==')'){
            while(st.top() != '('){
                postfix += st.top();
                st.pop();
            }
        }
        if(isalnum(i)){
            postfix += i;
        }
        else if(pres[i]){
            while(!st.is_empty() && pres[i] <= pres[st.top()]){
                postfix+=st.top();
                st.pop();
            }
            st.push(i);
        }
        else{
            st.push(i);
        }
    }
    return postfix;
}

string infixtoPrefix(string infix){
    reverse(infix.begin(), infix.end());
    for(auto& i: infix){
        if(i=='(') i = ')';
        else if(i==')') i = '(';
    }
    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int eval(int x, int y, char i){
    if(i=='^') return pow(y, x);
    else if(i=='/') return y/x;
    else if(i=='*') return y*x;
    else if(i=='-') return y-x;
    else if(i=='+') return y+x;
}

int evaluatePostfix(string postfix, bool flag=1){
    Stack st = Stack();
    for(auto& i: postfix){
        if(isalnum(i)){
            st.push(i);
        }else{
            int x = st.top(); st.pop();
            int y = st.top(); st.pop();
            st.push(eval(x, y, i));
        }
    }
    return st.top();
}

int evaluatePrefix(string prefix, bool flag=1){
    Stack st = Stack();
    reverse(prefix.begin(), prefix.end());
    for(auto& i: prefix){
        if(isalnum(i)){
            st.push(i);
        }else{
            int x = st.top(); st.pop();
            int y = st.top(); st.pop();
            st.push(eval(y, x, i));
        }
    }
    return st.top();
}

void menu(){
    cout << "----------------------------------------------------\n" ;
    cout << "1. Infix to postfix.\n";
    cout << "2. Infix to prefix.\n";
    cout << "3. Evaluate Expression.\n";
    cout << "4. Reset Infix String.\n";
    cout << "0. Exit.\n";
}

int main()
{
    int choice = 1, val;
    cout << "This Assignment is on Infix to Postfix/Postfix conversion ad evaluation;" << endl;
    cout << "-----------------------------------------------------------------------------\n" ;
    string infix , postfix, prefix;
    cout << "\nEnter the Infix String : ";
    cin >> infix;
    menu();
    do
    {
        cout << "----------------------------------------------------\n" ;
        cout << "Enter Your Choice from menu:";
        cin >> choice;
        switch(choice){
            case 1:
                postfix = infixToPostfix(infix);
                cout << "Postfix String  is :"<< postfix << endl;
                break;
            case 2:
                prefix = infixtoPrefix(infix);
                cout << "Prefix String  is :"<< prefix << endl;
                break;
            case 3:
                evaluatePostfix( infixToPostfix(infix) );
                break;
            case 4:
                cout << "\nEnter new Infix String : ";
                cin >> infix;
                break;
            case 0:
                break;
            default:
                cout << "Invalid Choice !!\n";
        }
    }
    while(choice);
    return 0;
}