#include <bits/stdc++.h>
using namespace std;

struct student 
{
	int roll;
	string name;
	float marks;
};

void display(student *p[], int i) 
{
	cout<< "S.No \t" << "Name\t" << "Roll\t" << "Marks\n";
	for(int j=0; j<i ; j++)
	{
		cout << j+1 << '\t';
		cout << p[j]->name << '\t' << p[j]->roll << '\t' << p[j]->marks << '\n';
	}
} 

void linear_search(student *p[], int i, float mar)
{
	bool found = 0;
	for (int j = 0 ; j<i ; j++)
	{ 
		if(p[j]->marks == mar)
		{
			if(found == 0) 
			{
				found = 1;
				cout<< "S.No \t" << "Name\t" << "Roll\t" << "Marks\n";
			}
			cout << i+1 << '\t';
			cout << p[j]->name << '\t' << p[j]->roll << '\t' << p[j]->marks << '\n';
		}
	}
	if( found == 0 )
	{
		cout << "Record Not found\n";
	}
}

void bubble_sort(student *p[], int n)
{
	cout << "Before Bubble Sort" <<endl;
	display(p,n);
	for(int k = n - 1; k >= 1; k--)
	{
		for(int j = 0; j < k;j++)
		{
			if(p[j]->roll > p[j+1]->roll)
			{
				student *temp;
				temp = p[j];
				p[j]  = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	cout << "After Bubble Sort" <<endl;
	display(p,n);
}

void insertion_sort(student *p[], int n)
{
	cout << "Before Insertion Sort" <<endl;
	display(p,n);
	for(int k = 1; k < n; k++)
	{
		student *temp;
		temp = p[k];
		int pos = k;
		for(int i = k-1 ; i >=0 ; i--)
		{
			if(p[i]->name > temp->name)
			{
				p[i+1]=p[i];
				pos = i;
			}
			else
			{
				break;
			}
		}
		p[pos]=temp;
	}
	cout << "After Insertion Sort" <<endl;
	display(p,n);
}

int partition(student *p[], int lb, int ub)
{
	float pivot = p[lb]->marks;
	int start = lb, end = ub;
	while(start < end)
	{
		while(start < ub && p[start]->marks <= pivot) start++;
		while(end > lb && p[end]->marks>pivot) end--;
		if(start< end)
		{
			swap(p[start], p[end]);
		}
	}
	swap(p[lb], p[end]);
	return end;
}

void Quicksort(student *p[], int lb, int ub)
{
	if(lb < ub)
	{
		int loc = partition(p, lb, ub);
		Quicksort(p, lb, loc - 1);
		Quicksort(p, loc + 1, ub);
	}
}

void quick_sort(student *p[], int n)
{
	cout << "Before Quick Sort" <<endl;
	display(p,n);
	Quicksort(p, 0, n-1);
	cout << "After Quick Sort" <<endl;
	display(p,n);
}

void binary_search(student *s[], int i, string nam)
{
	insertion_sort( s , i );
	int l = 0, r = i, m;
	bool found = 0;
	while( l <= r )
	{
		m = (l + r)/2;
		if( s[m]->name == nam)
		{
			found = 1;
			cout<< "S.No \t" << "Name\t" << "Roll\t" << "Marks\n";
			cout <<"1.\t"<< s[m]->name << '\t' << s[m]->roll << '\t' << s[m]->marks <<'\n';
			break;
		}
		else if( s[m]->name < nam )
		{
			l = m+1;
		}
		else
		{
			r = m-1;
		}
	}
	if(found == 0 )
	{
		cout << "Record not found"<<endl;
		return;
	}
}

int main() 
{ 
	student *s[60];
	int i = 0;
	bool cont = 1;
	do 
	{ 
		s[i] = new student;
		cout << "Enter the roll no , name, marks of the student " << endl;
		cin >> s[i]->roll >> s[i]->name >> s[i]->marks;
		i++; 
		cout << "Enter 0 if you want to stop entering data, or Enter 1 to continue adding data\n"; 
		cin >> cont;
	} 
	while (cont);
	int x=1; 
	do
	{
		cout << "Press 2 to Display Data \nPress 3 to Linear Search data \nPress 4 to Binary Search data\nPress 5 To Bubble Sort on roll number\nPress 6 to Insertion Sort on Name \nPress 7 to to Quick Sort on Marks\nPress 0 to exit\n" ; 
		cin >> x; 
		switch( x ) 
		{ 
			case 2: 
			{ 
				display( s , i); 
				break;
			} 
			case 3: 
			{ 
				cout << "Enter the CGPA of student you want to search for \n"; 
				float mrk;
				cin >> mrk; 
				linear_search( s, i, mrk);
				break;
			}
			case 4:
			{
				cout << "Enter the NAME of student you want to search for \n"; 
				string name; 
				cin >> name; 
				binary_search( s, i, name);
				break;
			}
			case 5:
			{
				bubble_sort(s,i);
				break;
			}
			case 6:
			{
				insertion_sort(s,i);
				break;
			}
			case 7:
			{
				quick_sort(s, i);
				break;
			}
			case 0:
			{
				break;
			}
			default:
			{ 
				cout << "Invalid value Enter again\n" ;
				break;
			} 
		} 
	}
	while(x);
}
