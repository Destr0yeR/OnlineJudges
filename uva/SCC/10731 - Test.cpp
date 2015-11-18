#include<bits/stdc++.h>
#define MAX 1001

using namespace std;

int V, E, L;

vector<int> graph[MAX];
vector<int> transpose[MAX];
vector<char> st[MAX];
map<char, int >m;
char rm[MAX];
stack<int> S;
int visited[MAX];

void init(){
	V = 0;
	m.clear();
	for(int i = 0 ; i < MAX ; ++i){
		graph[i].clear();
		transpose[i].clear();
		visited[i] = 0;
		st[i].clear();
	}
}

void built_transpose(){
	int sz, to;
	for(int from = 1 ; from <= V ; ++from){
		sz = graph[from].size();
		for(int i = 0 ; i < sz ; ++i){
			to = graph[from][i];
			transpose[to].push_back(from);
		}
	}
}

void dfs(int from){
	int to, sz = graph[from].size();
	visited[from] = 1;
	
	for(int i = 0 ; i < sz ; ++i){
		to = graph[from][i];
		if(visited[to] == 0)dfs(to);
	}
	
	S.push(from);
}

void dfs2(int from, int cmp){
	int to, sz = transpose[from].size();
	visited[from] = 1;
	st[cmp].push_back(rm[from]);
	
	for(int i = 0 ; i < sz ; ++i){
		to = transpose[from][i];
		if(visited[to] == 0)dfs2(to, cmp);
	}
}

bool _cmp(vector<char> a, vector<char> b){
	return a[0] < b[0];
}

void debug(vector<int> g[]){
	cout << "start of graph" << endl;
	for(int from  = 1 ; from <= V ; ++from){
		cout << from;
		for(int i = 0 ; i < g[from].size() ; ++i){
			int to = g[from][i];
			cout << " " << to;
		}
		cout << endl;
	}
	cout << "end of graph" << endl;
}

void scc(){
	//debug(graph);
	for(int i =  1; i <= V ; ++i)if(visited[i] == 0)dfs(i);
	built_transpose();
	//debug(transpose);
	memset(visited, 0, sizeof(visited));
	int cmp = 0, current, sz;
	while(!S.empty()){
		current = S.top();
		S.pop();
		if(visited[current] == 1)continue;
		dfs2(current, cmp);
		cmp++;
	}
	
	for(int i = 0 ; i < cmp ; ++i)sort(st[i].begin(), st[i].end());
	
	sort(st , st + cmp, _cmp);
	
	for(int i = 0 ; i < cmp ; ++i){
		sz = st[i].size();
		for(int j = 0 ; j < sz ; ++j){
			if(j)cout << " ";
			cout << st[i][j];
		}
		cout << endl;
	}
}

int main(){
	char a[5], b;
	//freopen("10731.in", "r", stdin);
	//freopen("10731.out", "w", stdout);
	int tc = 0;
	while(cin >> L){
		if(L == 0)break;
		if(tc++)cout<<endl;
		init();
		for(int i = 0 ; i < L ; ++i){
			for(int j = 0 ; j < 5 ; ++j){
				cin >> a[j];
				if(!m.count(a[j])){m[a[j]] = ++V;rm[V] = a[j];}
			}
			cin >> b;
			
			for(int j = 0 ; j < 5 ; ++j){
				if(b != a[j]){
					graph[m[b]].push_back(m[a[j]]);
				}
			}
		}
		
		scc();
	}
	
	return 0;
}
