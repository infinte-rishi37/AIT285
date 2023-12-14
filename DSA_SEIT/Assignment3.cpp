#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
    node(int val){
        data = val ;
        next = NULL;
    }
};

class circular_queue{
    int size, curr_size;
    node *front, *rear;
    public:
    circular_queue(int val){
        size = val;
        curr_size = 0;
        front = rear = NULL;
    }

    bool isFull(){
        return curr_size == size;
    }

    bool isEmpty(){
        return front == NULL;
    }

    void Enqueue(int data){
        if(isEmpty()){
            front = rear = new node(data);
            curr_size = 1;
        }
        else if(isFull()){
            cout << "Queue OverFlow\n";
        }
        else{
            node *temp = new node(data);
            rear->next = temp;
            rear = rear->next;
            curr_size++;
        }
    }

    void Dequeue(){
        if(isEmpty()){
            cout << "Queue Underflow\n";
        }
        else{
            cout << "Removed element " << front->data << " from front." << endl;
            node *temp=front;
            front = front->next;
            free(temp);
            curr_size--;
            if(curr_size == 0){
                front = rear = NULL;
            }
        }
    }

    void Display(){
        node *tmp = front;
        cout << "Element in Circular Queue are : \n";
        while(tmp!=NULL){
            cout << tmp->data << ' ';
            tmp = tmp->next;
        }
        cout << endl;
    }

    int Front(){
        return front->data;
    }
};

int main(){
    int size;
    cout << "Enter the size of Queue\n";
    cin >> size;
    circular_queue CQ = circular_queue(size);
    int choice = 1;
    cout << "Enter 1 to Enqueue\n";
    cout << "Enter 2 to Dequeue\n";
    cout << "Enter 3 to Display\n";
    cout << "Enter 0 to Exit\n";
    do{
        cout << "Enter Choice : ";
        cin >> choice;
        switch(choice){
            case 1:
                int val;
                cout << "Enter value to be inserted :";
                cin >> val;
                CQ.Enqueue(val);
                break;
            case 2:
                CQ.Dequeue();
                break;
            case 3:
                CQ.Display();
                break;
            case 0:
                break;
            default:
                cout << "INVALID VALUE , ENTER AGAIN ! :";
        }
    }while(choice);
}