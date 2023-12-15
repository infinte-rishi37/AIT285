#include <bits/stdc++.h>
using namespace std;

const int N = 1005, MX = 1e9;
vector<int> graph[N], level;
int adj[N][N];

vector<int> parent, Rank;
vector<pair<int,int>> edges;

void Set(){
    int n; 
    cout << "\nEnter the Number of edges to Add :";
    cin>>n;

    //reset
    for(int i=1;i<=N;i++){
        graph[i].clear();
    }
    Rank.clear();
    parent.clear();
    edges.clear();
    parent.resize(N);
    Rank.resize(N);

    cout << "\nStart\tEnd\tCost\n";
    for(int i=0;i<n;i++){
        int cost, u, v;
        cin>>u>>v>>cost;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges.push_back({u,v});
        adj[u][v] = adj[v][u] = cost;
    }
}

void Prims(int start){
    cout << "Performing Prims Algorithm\n" ;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > min_heap;
    min_heap.push({0, start});
    int vis[N] = {}, result = 0;
    while(min_heap.size()){
        pair<int,int> tmp = min_heap.top();
        int cost = tmp.first;
        int node = tmp.second;
        min_heap.pop();
        if(vis[node]) continue;
        vis[node]=1;
        result += cost;
        cout << "Selecting the edge that costs " << cost << " to reach node " << node << endl;
        for(auto & i: graph[node]){
            if(!vis[i]){
                min_heap.push({adj[i][node], i});
            }
        }
    }
    cout << "Total cost for MST by Prims Algorithm: " << result << endl;
}


int find_parent(int p){
    if(p==parent[p]) return p;
    return parent[p] = find_parent(parent[p]);
}

void union_set(int u, int v){
    int a = find_parent(u);
    int b = find_parent(v);
    if(a!=b){
        if(Rank[a]<Rank[b]){
            parent[a] = b;
        }
        else if(Rank[a]>Rank[b]){
            parent[b] = a;
        }
        else{
            parent[a] = b;
            Rank[b]++;
        }
    }
}

void kruskal(){
    cout << "Performing Kruskal Algorithm\n" ;
    for(int i=0;i<N;i++){
        parent[i]=i;
        Rank[i]=0;
    }
    multimap<int,pair<int,int>> mp;
    for(auto& i: edges){
        int u = i.first, v = i.second;
        mp.insert( { adj[u][v], {u, v} } );
    }
    int result = 0;
    for(auto & i: mp){
        int cost = i.first;
        int u = i.second.first;
        int v = i.second.second;
        if(find_parent(u) != find_parent(v)){
            cout << "Selecting the edge that costs " << cost << " to beetween " << u << " and " << v << endl;
            result += cost;
            union_set(u, v);
        }
    }
    cout << "Total cost for MST by Kruskal Algorithm: " << result << endl;
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
	cout << "\n\t2. MST Using Prims ";
	cout << "\n\t3. MST Using Kruskal ";
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
            Prims(1);
            break;
            case 3:
            kruskal();
            break;
            default:
            choice = 0;
        }
    }while(choice);
}