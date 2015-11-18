#include<bits/stdc++.h>
#define MAX 10001
using namespace std;

int V, m, disc;
vector<int> ady[MAX];
int parent[MAX];
int visited[MAX];
int low[MAX];
int dist[MAX];

struct city{
	int v, i;
	city(){
		
	}
	city(int _i,int _v){
		v = _v;
		i = _i;
	}
}cit[MAX];

bool cmp(city a, city b){
	if(a.v == b.v)return a.i < b.i;
	return a.v > b.v;
}

void init(){
	disc = 0;
	for(int i = 0 ; i < V ; ++i){
		cit[i] = city(i, 0);
		ady[i].clear();
		visited[i] = 0;
		parent[i] = -1;
	}
}

void dfs(int from){
	visited[from] = 1;
	int to, sz, child = 0;
	sz = ady[from].size();
	low[from] = dist[from] = disc++;
	for(int i = 0 ; i < sz ; ++i){
		to = ady[from][i];
		
		if(visited[to] == 0){
			child++;
			parent[to] = from;
			dfs(to);
			
			low[from] = min(low[to], low[from]);
			
			if(parent[from] == -1 && child > 1){
				cit[from].v++;
			}
			else if(parent[from] != -1 && low[to] >= dist[from]){
				cit[from].v++;
			}
		}
		else if(to != parent[from]){
			low[from] = min(low[from], dist[to]);
		}
	}
}

int main(){
	int from, to;
	while(cin >> V >> m){
		if(V == 0 && m == 0)break;
		
		init();
		while(cin >> from >> to){
			if(from == -1 && to == -1)break;
			ady[from].push_back(to);
			ady[to].push_back(from);
		}
		
		for(int i = 0 ; i < V ; ++i){
			if(visited[i] == 0) dfs(i);
		}
		
		sort(cit, cit + V, cmp);
		
		for(int i = 0 ; i < m ; ++i){
			cout << cit[i].i << " " << cit[i].v+1 << endl;
		}
		cout<<endl;
	}
	
	return 0;
}
