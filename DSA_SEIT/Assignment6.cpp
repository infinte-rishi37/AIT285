#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    bool rbit, lbit;
    node *left, *right;
    node(int val){
        data = val;
        rbit = lbit = false;
        left = right = NULL;
    }
};

class TBST{
    public:

    node *head, *root;
    
    TBST(){
        head = new node(999);
        head->left = head;
        head->lbit = true;
        root = NULL;
    }

    void insert(int data, node *par){
        if(root == NULL){
            root = new node(data);
            head->right = head;
            head->rbit = 1; 
            root->left = root->right = head;
            par = root;
        }
        else if(data == par->data){
            cout << "Inseting Multiple value is not possible\n";
        }
        else if(data > par->data){
            if(par->rbit == 0){
                node *tmp = new node(data);
                tmp->left = par;
                tmp->right = par->right;
                par->right = tmp;
                par->rbit = 1;
            }
            else insert(data, par->right);
        }
        else if(data < par->data){
            if(par->lbit == 0){
                node *tmp = new node(data);
                tmp->left = par->left;
                tmp->right = par;
                par->left = tmp;
                par->lbit = 1;
            }
            else insert(data, par->left);
        }
    }

    void inorder(){
        node *tmp = root;
        while(tmp!=head){
            while(tmp->lbit){
                tmp = tmp->left;
            }
            cout << tmp->data << ' ';
            while(!tmp->rbit){
                tmp = tmp->right;
                if(tmp!=head){
                    cout << tmp->data <<' ';
                }
            }
            tmp=tmp->right;
        }
        cout << endl;
    }

    void preorder(){
        node *tmp = root;
        while(tmp!=head){
            while(tmp->lbit){
                cout << tmp->data <<' ';
                tmp = tmp->left;
            }
            cout << tmp->data << ' ';
            while(!tmp->rbit){
                tmp=tmp->right;
            }
            tmp=tmp->right;
        }
        cout << endl;
    }
};

void menu(){
    cout << "==============MENU=============\n";
    cout << "1. Insert values\n";
    cout << "2. InOrder traversal\n";
    cout << "3. PreOrder traversal\n";
    cout << "*. Exit\n";
    cout << "===============================\n";
    cout << "Enter your Choice : ";
}

signed main(){
    TBST tree = TBST();
    int choice = 1, n;
    do{
        menu();
        cin>>choice;
        switch(choice){
            case 1:
            cout << "Enter number of values you want to Insert.\n";
            cin>>n;
            cout << "Enter "<<n<<" values with spaces.\n";
            for(int i=0;i<n;i++){
                int x;
                cin>>x;
                tree.insert(x, tree.root);
            }
            break;
            case 2:
            tree.inorder();
            break;
            case 3:
            tree.preorder();
            break;
            default:
            choice = 0;
        }
    }while(choice);
}