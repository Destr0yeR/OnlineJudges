#include<bits/stdc++.h>
#define MAX 101
using namespace std;

int V, E, cont;

int graph[MAX][MAX];
vector<string> sc[MAX];
int visited[MAX];
int used[MAX];

vector<int> rans;
vector<string> ans;
stack<int> S;
map<string, int> m;
string rm[MAX];

int index(string s){
	if(!m.count(s)){
		int sz = m.size() + 1;
		rm[sz] = s;
		return m[s] = sz;
	}
	return m[s];
}

void reset(){
	memset(visited, 0, sizeof(visited));
}

void init(){
	reset();
	memset(graph, 0, sizeof(graph));
	memset(used, 0, sizeof(used));
	m.clear();
	rans.clear();
	ans.clear();
	for(int i = 0 ; i <= V ; ++i)sc[i].clear();
}

void dfs(int from){
	visited[from] = 1;
	
	for(int to = 1 ; to <= V ; ++to){
		if(visited[to] == 0 && graph[from][to] == 1)
			dfs(to);
	}
	
	S.push(from);
}

void dfs2(int from, int comp){
	visited[from] = 1;
	
	sc[comp].push_back(rm[from]);
	
	for(int to = 1 ; to <= V ; ++to){
		if(visited[to] == 0 && graph[to][from] == 1)
			dfs2(to, comp);
	}
}

void dfs3(int from){
	ans.push_back(rm[from]);
	visited[from] = 1;
	
	for(int to = 1 ; to <= V ; ++to){
		if(visited[to] == 0 && graph[from][to])dfs3(to);
	}
}

void scc(){
	for(int i = 1 ; i <= V ; ++i)if(visited[i] == 0)dfs(i);
	reset();
	
	int current, comp = 0, sz;
	
	while(!S.empty()){
		current = S.top();
		S.pop();
		
		if(visited[current] == 1)continue;
		dfs2(current, comp);
		
		sz = sc[comp].size();
		
		if(sz > 1 || used[current] == 0){
			for(int j = 0 ; j < sz ; ++j){
				rans.push_back(index(sc[comp][j]));
			}
		}
		
		comp++;
	}
	
	reset();
	
	sz = rans.size();
	
	for(int i = 0 ; i < sz ; ++i){
		if(visited[rans[i]] == 0)dfs3(rans[i]);
	}
	
	sort(ans.begin(), ans.end());
	sz = ans.size();
	cout << ans.size() << endl;
	for(int i = 0 ; i < sz ; ++i){
		if(i)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}

void _trim(string s){
	string from, to;
	stringstream ss(s);
	
	ss >> from;
	
	while(ss >> to){
		graph[index(from)][index(to)] = 1;
		used[index(from)] = 1;
	}
}

int main(){
	string line;
	
	while(getline(cin, line)){
		stringstream ss(line);
		ss >> V;
		if(V == 0)break;
		init();

		for(int i = 1 ; i <= V ; ++i){
			getline(cin, line);
			_trim(line);
		}
		
		scc();
	}
}
