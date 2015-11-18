#include<bits/stdc++.h>
#define MAX 101

using namespace std;

int V, orden;
int visited[MAX], used[MAX], parent[MAX], low[MAX], dist[MAX];
vector<int> ady[MAX], ap;

vector<int> toVector(string s){
	int k = 0, sz = s.size(), n;
	vector<int> v;
	while(k < sz){
		while(s[k] == ' ')k++;
		n = 0;
		if( k == sz)break;
		while(s[k] != ' ' && k < sz){
			n *= 10;
			n += s[k] - '0';
			k++;
		}
		v.push_back(n);
		k++;
	}
	return v;
}

void dfs(int from){
	dist[from] = low[from] = ++orden;
	visited[from] = 1;
	int sz, to;
	sz = ady[from].size();
	int child = 0;
	
	for(int i = 0 ; i < sz ; ++i){
		to = ady[from][i];
		if(!visited[to]){
			child++;
			parent[to] = from;
			dfs(to);
			low[from] = min(low[from], low[to]);
			
			if(parent[from] == -1 && child > 1){
				if(used[from] == 0){
					used[from] = 1;
					ap.push_back(from);
				}
			}
			else if(parent[from] != -1 && low[to] >= dist[from]){
				if(used[from] == 0){
					used[from] = 1;
					ap.push_back(from);
				}
			}
		}
		else if(to != parent[from]){
			low[from] = min(low[from], dist[to]);
		}
	}
}

void init(){
	for(int i = 0 ; i <= V ; ++i){
		ady[i].clear();
		parent[i] = -1;
		used[i] = 0;
		visited[i] = 0;
	}
	orden = 0;
	ap.clear();
}

int main(){
	string s;
	vector<int> v;
	int sz;
	while(cin >> V){
		if(V == 0)break;
		cin.ignore();
		init();
		while(getline(cin, s)){
			v = toVector(s);
			if(v.size() == 1 && v[0] == 0)break;
			sz = v.size() ;
			for(int i = 1 ; i < sz; ++i){
				ady[v[0]].push_back(v[i]);
				ady[v[i]].push_back(v[0]);
			}
		}
		
		for(int i = 1 ; i <= V ; ++i)
			if(!visited[i])
				dfs(i);
				
		cout << ap.size() << endl;
	}
	
	return 0;
}
