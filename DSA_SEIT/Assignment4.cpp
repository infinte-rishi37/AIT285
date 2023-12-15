#include <bits/stdc++.h>
using namespace std;

struct node{
    char data;
    node *left, *right;
    node(char val){
        data = val;
        left = right = NULL;
    }
};

class ExpTree{
    public:
    node *root;
    stack<node*> st;
    ExpTree(){
        root = NULL;
    }

    void createPostfix(string s){
        for(auto& i: s){
            node* tmp = new node(i);
            if(isalnum(i)){
                st.push(tmp);
            }
            else{
                node *a = st.top(); st.pop();
                node *b = st.top(); st.pop();
                tmp->left = b;
                tmp->right = a;
                st.push(tmp);
            }
        }
        root = st.top();
        st.pop();
        if(st.size()){
            cout << "Invalid Expression\n";
            while(st.size()) st.pop();
        }
    }

    void createPrefix(string s){
        reverse(s.begin(), s.end());
        for(auto& i: s){
            node* tmp = new node(i);
            if(isalnum(i)){
                st.push(tmp);
            }
            else{
                node *a = st.top(); st.pop();
                node *b = st.top(); st.pop();
                tmp->left = a;
                tmp->right = b;
                st.push(tmp);
            }
        }
        root = st.top();
        st.pop();
        if(st.size()){
            cout << "Invalid Expression\n";
            while(st.size()) st.pop();
        }
    }

    void inorder(node* par){
        if(par!=NULL){
            inorder(par->left);
            cout << par->data << ' ';
            inorder(par->right);
        }
    }

    void preorder(node* par){
        if(par!=NULL){
            cout << par->data << ' ';
            preorder(par->left);
            preorder(par->right);
        }
    }

    void postorder(node* par){
        if(par!=NULL){
            postorder(par->left);
            postorder(par->right);
            cout << par->data << ' ';
        }
    }
};

void menu(){
    cout << "1. Start From PostFix Expression\n";
    cout << "2. Start From PreFix Expression\n";
    cout << "3. InOrder\n";
    cout << "4. PreOrder\n";
    cout << "5. PostOrder\n";
    cout << "0. Exit\n";
    cout << "Enter Your Choice\n";
}

signed main(){
    string s;
    int choice=1;
    ExpTree tree;
    do{
        menu();
        cin>>choice;
        switch(choice){
            case 1:
            cout << "Enter postfix String : ";
            cin >> s;
            tree = ExpTree();
            tree.createPostfix(s);
            break;
            case 2:
            cout << "Enter prefix String : ";
            cin >> s;
            tree = ExpTree();
            tree.createPrefix(s);
            break;
            case 3:
            tree.inorder(tree.root);
            cout << endl;
            break;
            case 4:
            tree.preorder(tree.root);
            cout << endl;
            break;
            case 5:
            tree.postorder(tree.root);
            cout << endl;
            break;
        }
    }while(choice);
}