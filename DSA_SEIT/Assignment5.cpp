#include <bits/stdc++.h>
using namespace std;

class BST{
    struct node{
        int data;
        node *left , *right;
        node(int x){
            data = x;
            left = right = NULL;
        }
    };
    public:
    node *root;
    int depth = 0;

    BST(){
        root = NULL;
    }

    void Insert(int x,node *par){
        if(root==nullptr){
            // cout << "node\n";
            root = new node(x);
        }
        else if(par->data == x){
            cout << "Cannot insert multiple values into a BST.\n";
        }
        else if(par->data > x){
            // cout << "left\n";
            if(par->left == NULL) par->left = new node(x);
            else Insert(x, par->left);
        }
        else{
            // cout << "right\n";
            if(par->right == NULL) par->right = new node(x);
            else Insert(x, par->right);
        }
    }

    void Delete(int x, node* par){
        if(par==NULL){
            cout << "No such Node found\n" ;
        }
        else if( x == par->data ){
            if(par->left!=NULL && par->right!=NULL){
                node *tmp = par->right;
                while(par->left!=NULL){
                    tmp = tmp->left;
                }
                par->data = tmp->data;
                free(tmp);
            }
            else{
                if(par->left!=NULL){
                    par = par->left;
                }
                else{
                    par = par->right;
                }
            }
        }
        else if(x > par->data){
            Delete(x, par->right);
        }
        else{
            Delete(x, par->left);
        }
    }

    void Search(int x, node* par){
        if( par == NULL ){
            cout << "No Such data found.\n";
        }
        else if(par->data == x){
            cout << "Data found.\n";
        }
        else if(par->data > x){
            Search(x, par->left);
        }
        else{
            Search(x, par->right);
        }
    }

    void InOrder(node *par){
        if(par!=NULL){
            InOrder(par->left);
            cout << par->data << ' ';
            InOrder(par->right);
        }
    }

    void InOrderNr(){
        node* tmp = root;
        stack<node*> st;
        while(tmp != NULL){
            st.push(tmp);
            tmp = tmp->left;
        }
        while(st.size()){
            tmp = st.top();
            st.pop();
            cout << tmp->data << ' ' ;
            tmp = tmp->right;
            while(tmp!=NULL){
                st.push(tmp);
                tmp = tmp->left;
            }
        }
    }

    void PreOrder(node *par){
        if(par!=NULL){
            cout << par->data << ' ';
            PreOrder(par->left);
            PreOrder(par->right);
        }
    }

    void PreOrderNr(){
        node* tmp = root;
        stack<node*> st;
        while(tmp != NULL){
            st.push(tmp);
            cout << tmp->data << ' ' ;
            tmp = tmp->left;
        }
        while(st.size()){
            tmp = st.top();
            st.pop();
            tmp = tmp->right;
            while(tmp!=NULL){
                st.push(tmp);
                cout << tmp->data << ' ' ;
                tmp = tmp->left;
            }
        }
    }

    void PostOrder(node *par){
        if(par!=NULL){
            PostOrder(par->left);
            PostOrder(par->right);
            cout << par->data << ' ';
        }
    }
    
    void PostOrderNr(){
        node* tmp = root;
        stack<node*> st, sst;
        while(tmp != NULL){
            st.push(tmp);
            sst.push(tmp);
            tmp = tmp->right;
        }
        while(st.size()){
            tmp = st.top();
            st.pop();
            tmp = tmp->left;
            while(tmp!=NULL){
                st.push(tmp);
                sst.push(tmp);
                tmp = tmp->right;
            }
        }
        while(sst.size()){
            cout << sst.top()->data << ' ';
            sst.pop();
        }
        cout << endl;
    }

    void Display(){
        cout << "\n1. In-order Traversal.";
        cout << "\n2. Pre-order Traversal.";
        cout << "\n3. Post-order Traversal.";
        int x;
        cout << "Enter Your Choice :";
        cin >> x;
        while(x>3 || x<1){
            cout << "\nInvalid Choice. Enter again : ";
            cin >> x;
        }
        if(x==1){
            InOrderNr();
        }
        else if(x==2){
            PreOrderNr();
        }
        else{
            PostOrderNr();
        }
        cout << endl;
    }

    void updateDepth(int level, node* par){
        if(par!=NULL){
            depth = max(level+1, depth);
            updateDepth(level+1, par->right);
            updateDepth(level+1, par->left);
        }
    }

    void DisplayParent(node* par){
        cout << "\nParent :" << par->data << " ,has nodes ";
        if(par->left!=NULL){
            cout << "left -> " << par->left->data <<" ";
        }
        if(par->right!=NULL){
            cout << "right -> " << par->right->data;
        }
        if(par->left!=NULL){
            DisplayParent(par->left);
        }
        if(par->right!=NULL){
            DisplayParent(par->right);
        }
    }

    void DisplayLeaf(node* par){
        bool flag = true;
        if(par->left!=NULL){
            DisplayLeaf(par->left);
            flag = false;
        }
        if(par->right!=NULL){
            DisplayLeaf(par->right);
            flag = false;
        }
        if(flag){
            cout << par->data << ' ';
        }
    }

    void DisplayLevelWise(){
        queue<node*> Q;
        map<node*, int> level;
        Q.push(root);
        level[root] = 0;
        int currlevel = 0;
        cout << "Level" << currlevel << ": ";
        while(Q.size()){
            node* u = Q.front();
            Q.pop();
            if(currlevel<level[u]){
                currlevel++;
                cout << '\n' << "Level" << currlevel << ": ";
            }
            cout << u->data << ' ';
            if(u->left!=NULL){
                Q.push(u->left);
                level[u->left] = level[u] + 1;
            }
            if(u->right!=NULL){
                Q.push(u->right);
                level[u->right] = level[u] + 1;
            }
        }
    }

    void mirror(node* par){
        if(par!=NULL){
            mirror(par->left);
            mirror(par->right);
            node* tmp = par->left;
            par->left = par->right;
            par->right = tmp;
        }
    }
};

void menu(){
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Display\n";
    cout << "4. Display Depth\n";
    cout << "5. Display Mirror Image\n";
    cout << "8. Display Parent with Child nodes\n";
    cout << "9. Display Leaf Nodes\n";
    cout << "10.Level Wise Display\n";
    cout << "0. Exit\n";
}

signed main(){
    BST bst;
    cout << "**BINARY SEARCH TREE**\n";
    menu();
    int choice = 1;
    do{
        cout << "\nEnter your choice : ";
        cin >> choice;
        int n; 
        switch(choice){
            case 1:
                cout << "Enter number of values you want to Insert.\n";
                cin>>n;
                cout << "Enter "<<n<<" values with spaces.\n";
                for(int i=0;i<n;i++){
                    int x;
                    cin>>x;
                    bst.Insert(x, bst.root);
                }
                break;
            case 2:
                cout << "Enter value you want to Delete.\n";
                cin>>n;
                bst.Delete(n, bst.root);
                break;
            case 3:
                bst.Display();
                break;
            case 4:
                bst.updateDepth(0, bst.root);
                cout << "Depth : " << bst.depth << "." << endl;
                break;
            case 5:
                bst.mirror(bst.root);
                bst.DisplayLevelWise();
                break;
            case 8:
                bst.DisplayParent(bst.root);
                cout << endl;
                break;
            case 9:
                bst.DisplayLeaf(bst.root);
                cout << endl;
                break;
            case 10:
                bst.DisplayLevelWise();
                cout << endl;
                break;
            default:
                cout << "Invalid Value ! Enter again.\n";
        }
    }while(choice);
}