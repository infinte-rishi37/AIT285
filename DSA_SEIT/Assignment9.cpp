#include <bits/stdc++.h>
using namespace std;

void heapify_maxheap(int arr[], int n, int i){
    int largest = i;
    int l = i*2+1;
    int r = i*2+2;

    if(l<n && arr[l]>arr[i]){
        largest = l;
    }

    if(r<n && arr[r]>arr[i]){
        largest = r;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);

        heapify_maxheap(arr, n, largest);
    }
}

void heapify_minheap(int arr[], int n, int i){
    int smallest = i;
    int l = i*2+1;
    int r = i*2+2;

    if(l<n && arr[l]<arr[i]){
        smallest = l;
    }

    if(r<n && arr[r]<arr[i]){
        smallest = l;
    }

    if(smallest != i){
        swap(arr[smallest], arr[i]);

        heapify_minheap(arr, n, smallest);
    }
}

void heapSort_maxHeap(int arr[], int n){
    for(int i=n/2-1;i>=0;i--){
        heapify_maxheap(arr, n, i);
    }

    for(int i=n-1 ; i>0; i--){
        swap(arr[0], arr[i]);
        heapify_maxheap(arr, i, 0);
    }
}

void heapSort_minHeap(int arr[], int n){
    for(int i=n/2 -1;i>=0;i--){
        heapify_minheap(arr, n, i);
    }

    for(int i=n-1; i>0; i--){
        swap(arr[0], arr[i]);
        heapify_minheap(arr, i, 0);
    }
}

void Display(int arr[], int n){
    cout << "\nElements : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
}

void menu(){
    cout << "\n=============================MENU==================================";
	cout << "\n\t1. Enter Array ";
	cout << "\n\t2. Sorting by Min-Heap ";
	cout << "\n\t3. Sorting by Max-Heap ";
	cout << "\n\t*. Exit";
	cout << "\n===================================================================";
	cout << "\n Enter your choice : ";
}

signed main(){
    int arr[50], n, choice=1;
    do{
        menu();
        cin>>choice;
        switch(choice){
            case 1:
            cout << "Enter the Size of Array(1-50) :";
            cin>>n;
            for(int i=0;i<n;i++){
                cout << "\nElement " << i+1 <<" : ";
                cin>>arr[i];
            }
            break;
            case 2:
            heapSort_minHeap(arr, n);
            Display(arr, n);
            break;
            case 3:
            heapSort_maxHeap(arr, n);
            Display(arr, n);
            break;
            default:
            choice = 0;
        }
    }while(choice);
}