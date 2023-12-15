#include <bits/stdc++.h>
using namespace std;

const int N = 1005, MX = 1e9;
vector<int> graph[N], level;
int adj[N][N];

void Set(){
    int n; 
    cout << "\nEnter the Number of edges to Add :";
    cin>>n;
    cout << "\nStart\tEnd\tCost\n";
    for(int i=0;i<n;i++){
        int cost, u, v;
        cin>>u>>v>>cost;
        graph[u].push_back(v);
        graph[v].push_back(u);
        adj[u][v] = adj[v][u] = cost;
    }
}

void Djikstra(){
    int root;
    cout << "Enter the Source City :";
    cin >> root;
    level = vector<int> (N,MX);
    level[root] = 0;
    queue<int> Q;
    map<int,int> vis;
    Q.push(root);
    while(Q.size()){
        int u = Q.front();
        Q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto& i: graph[u]){
            level[i] = min(level[u]+adj[u][i], level[i]);
            if(!vis[i]) Q.push(i);
        }
    }
}

void showDis(){
    int city;
    cout << "\nEnter the City to show Minimum Cost :";
    cin>>city;
    cout << "The Minimum cost is " << level[city] << endl;
}

void menu(){
    cout << "\n=============================MENU==================================";
	cout << "\n\t1. Input Graph ";
	cout << "\n\t2. Select Starting Point ";
	cout << "\n\t3. View Cost to reach a city ";
	cout << "\n\t*. Exit";
	cout << "\n===================================================================";
	cout << "\n Enter your choice : ";
}

signed main(){
    int choice;
    do{
        menu();
        cin>>choice;
        switch(choice){
            case 1:
            Set();
            break;
            case 2:
            Djikstra();
            break;
            case 3:
            showDis();
            break;
            default:
            choice = 0;
        }
    }while(choice);
}