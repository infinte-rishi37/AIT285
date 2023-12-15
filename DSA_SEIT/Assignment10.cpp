#include<bits/stdc++.h>
using namespace std;

const string filename = "data.txt";

struct Student{
private:
    string name;
    int roll_no;
    float marks;
    string address;
    string filename = "student.txt";

public:
    Student(){}

    void Create(){
        ofstream outfile(filename, ios::out);
        cout << "The database file is Created !\n";
    }

    void Display(){
        ifstream infile(filename, ios::in);
        infile.clear();
        infile.seekg(0);
        int sno = 1;
        cout << "\nS.no\tRoll\tName\tMarks\tAddress\n";
        string line;
        while( getline(infile, line) ){
            stringstream st(line);
            string s;
            cout << sno << ".\t" ;
            while(st>>s){
                cout << s <<'\t';
            }
            cout << endl;
            sno++;
        }
        infile.close();
    }

    void Add(){
        ofstream out(filename, ios::app);
        int n;
        cout << "Enter no of entries that you want to add : ";
        cin >> n;
        Student s;
        cout << "\nRoll\tName\tMarks\tAddress\n";
        for (int i = 0; i < n; i++) {
            cin >> s.roll_no >> s.name >> s.marks >> s.address;
            out << s.roll_no << " " << s.name << " " << s.marks << " " << s.address << endl;
        }
        cout << endl;
        out.close();
    }

    void Delete(){
        ofstream outfile("new.txt", ios::out);
        ifstream infile(filename , ios::in);
        cout << "Enter the Roll No that you want to delete : ";
        string key;
        cin >> key;
        bool flag = false;
        string line, s;
        while(getline(infile, line)){
            stringstream st(line);
            st>>s;
            if(s==key){
                flag = true;
                continue;
            }
            outfile << s << ' ';
            while(st>>s){
                outfile << s << ' ';
            }
            outfile << endl;
        }
        if(flag){
            outfile.close();
            infile.close();
            remove("student.txt");
            rename("new.txt", "student.txt");
        }else{
            cout << "No Data with such name exists\n";
        }
    }

    void Update(){
        ofstream outstream("new.txt", ios::out);
        ifstream instream(filename, ios::in);
        Student S;
        cout << "Enter the details of Student to update \n";
        cout << "\nRoll\tName\tMarks\tAddress\n";
        cin >> S.roll_no >> S.name >> S.marks >> S.address;
        string line, s;
        bool flag = 0;
        while(getline(instream, line)){
            stringstream st(line);
            Student tmp;
            st >> tmp.roll_no >> tmp.name >> tmp.marks >> tmp.address;
            if(tmp.roll_no == S.roll_no){
                flag = 1;
                tmp = S;
            }
            outstream << tmp.roll_no << ' ' << tmp.name << ' ' << tmp.marks << ' ' << tmp.address << endl;
        }
        if(flag){
            outstream.close();
            instream.close();
            remove("student.txt");
            rename("new.txt", "student.txt");
        }else{
            cout << "No Data with such name exists\n";
        }
    }

    void Search(){
        ifstream instream(filename, ios::in);
        cout << "Enter the Roll No of Student to Search \n";
        string key;
        cout << "Roll : ";
        cin >> key;
        string line, s;
        bool flag = 0;
        while(getline(instream, line)){
            stringstream st(line);
            Student tmp;
            cout << line << endl;
            st >> tmp.roll_no >> tmp.name >> tmp.marks >> tmp.address;
            if(tmp.roll_no == stoi(key)){
                flag = 1;
                cout << "\nRoll\tName\tMarks\tAddress\n";
                cout <<' '<< tmp.roll_no <<' '<< tmp.name <<' '<< tmp.marks <<' '<< tmp.address << endl;
            }
        }
        if(!flag){
            cout << "Data not found\n";
        }
    }
};

void menu(){
    cout << "\nChoose what operation you want\n";
    cout << "1) Create a new students database\n";
    cout << "2) Display students database\n";
    cout << "3) Insert new entries\n";
    cout << "4) Update entries\n";
    cout << "5) Delete entry\n";
    cout << "6) Search an entry\n";
    cout << "7) Exit\n";
    cout << "Please select a choice :";
}

signed main(){
    Student student;
    int choice;
    do {
        menu();
        cin >> choice;
        switch(choice){
            case 1:
            student.Create();
            break;
            case 2:
            student.Display();
            break;
            case 3:
            student.Add();
            break;
            case 4:
            student.Update();
            break;
            case 5:
            student.Delete();
            break;
            case 6:
            student.Search();
            break;
            case 0:
            break;
            default: {
                cout << "Invalid Input\n";
            }
        }

    } while (choice);
}