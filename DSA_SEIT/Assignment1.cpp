#include <bits/stdc++.h>
using namespace std;

struct student{
	int roll;
	string name;
	float sgpa;
	student(int roll_no, string Name, float Sgpa){
		roll = roll_no;
		name = Name;
		sgpa = Sgpa;
	}
};

void Display(student *s[], int n){
	cout << "\nS.no :\t RollNo \t Name \t sgpa";
	for(int i=0;i<n;i++){
		cout << "\n" << i+1 << ".\t" << s[i]->roll << "\t" << s[i]->name << "\t" << s[i]->sgpa ;
	}
}

void bubbleSort(student *s[], int n){
	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			if(s[j]->roll < s[j-1]->roll){
				student *temp = s[j];
				s[j]=s[j-1];
				s[j-1]=temp;
			}
		}
	}
}

void insertionSort(student *s[], int n){
	for(int i=1;i<n;i++){
		student *temp = s[i];
		int j=i;
		while(s[j]->name >= temp->name && j>0){
			s[j] = s[j-1];
			j--;
		}
		s[j] = temp;
	}
}

int partition(student *s[], int lb, int ub){
	int start = lb, end = ub;
	float pivot = s[start]->sgpa;
	while(start<end){
		while( start<end && s[start]->sgpa <= pivot ){
			start++;
		}
		while( start<end && s[end]->sgpa > pivot ){
			end--;
		}
		if(s[start]->sgpa == s[end]->sgpa){
			student *temp = s[end];
			s[end] = s[start];
			s[start] = temp;
		}
	}
	return end;
}

void quickSort(student *s[], int lb, int ub){
	if(lb<ub){
		int mid = partition(s, lb, ub);
		quickSort(s, lb, mid-1);
		quickSort(s, mid+1, ub);
	}
}

void linear_search(student *s[], float find, int n){
	bool flag = false;
	int c=1;
	for(int i=0;i<n;i++){
		if(flag == false){
			flag = true;
			cout << "\nS.no :\t RollNo \t Name \t sgpa";
		}
		if(s[i]->sgpa == find){
			cout << "\n" << c << ".\t" << s[i]->roll << "\t" << s[i]->name << "\t" << s[i]->sgpa ;
			c++;
		}
	}
	if(!flag){
		cout << "\nData Not Found";
	}
}

void binary_search(student *s[], string find, int n){
	bool flag = false;
	int start = 0, end = n-1;
	while(start<=end){
		int mid = (start+end)/2;
		if(s[mid]->name==find){
			flag = true;
			cout << "\n RollNo \t Name \t sgpa";
			cout << "\n" << s[mid]->roll << "\t" << s[mid]->name << "\t" << s[mid]->sgpa ;
		}
		else if(s[mid]->name>find){
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}
	if(!flag){
		cout << "\nData Not Found";
	}
}

void menu(){
	cout << "\n=============================MENU==================================";
	cout << "\n\t1. Create Student DataBase ";
	cout << "\n\t2. Arrange Student Data by Roll Number(Bubble Sort) ";
	cout << "\n\t3. Arrange Student Data by Name (Insertion Sort) ";
	cout << "\n\t4. Display List of ten toppers (Quick Sort)";
	cout << "\n\t5. Find Student data by SGPA (Linear Search)";
	cout << "\n\t6. Find Student data by Name (Binary Search)";
	cout << "\n\t0. Exit";
	cout << "\n===================================================================";
	cout << "\n Enter your choice : ";
}

int main(){
	int choice = 1, n;
	student *arr[50];
	do{
		menu();
		cin>>choice;
		switch(choice) {
			case 1:
				cout << "\nEnter Number of students you want to add (1-15):";
				cin >> n;
				cout << "\nInput data : \t RollNo \t Name \t sgpa";
				for(int i=0;i<n;i++){
					cout << "\nStudent " <<i+1<<" :\t";
					int roll;
					string name;
					float sgpa;
					cin >> roll >> name >> sgpa;
					arr[i] = new student(roll, name , sgpa);
				}
				cout << " Added Records Successfully \n";
				break;
			case 2:
				bubbleSort(arr, n);
				Display(arr, n);
			break;
			case 3:
				insertionSort(arr, n);
				Display(arr, n);
			break;
			case 4:
				quickSort(arr, 0, n-1);
				Display(arr, 10);
			break; 
			case 5:
				quickSort(arr, 0, n-1);
			float find;
			cout << "\nEnter the sgpa to find :";
			cin>>find;
				linear_search(arr, find, n);
			break;
			case 6:
				insertionSort(arr, n);
				string fin;
				cout << "\nEnter the sgpa to find :";
				cin>>fin;
				binary_search(arr, fin, n);
			break;
			case 0:
			break;
		}
	}while(choice);
}