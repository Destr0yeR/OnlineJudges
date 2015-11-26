#include<bits/stdc++.h>

#define MAX 100005
using namespace std;

typedef unsigned long ull;

struct par{
	ull w;
	int to;
	
	par(){}
	par(int _to, int _w){to = _to; w = _w;}
};

vector<par> ady[MAX];
bitset<MAX> visited;

int V;

ull dfs(int curr){
	visited[curr] = 1;
	
	int sz = ady[curr].size(), to;
	ull w, maxi = 0, aux;
	
	for(int i = 0 ; i < sz ; ++i){
		to = ady[curr][i].to;
		w = ady[curr][i].w;
		if(visited[to] == 1)continue;
		aux = dfs(to) + w;
		maxi = max(maxi, aux);
	}
	return maxi;
}

int main(){
	int from, to;
	ull w;
	
	while(cin >> V){
		visited.reset();
		
		ull total = 0;
		
		for(int i = 1 ; i < V ; ++i){
			cin >> from >> to >> w;
			ady[from].push_back(par(to, w));
			ady[to].push_back(par(from, w));
			total += w;
		}
		
		total*=2;
		
		cout << total - dfs(1) << endl;
		
		for(int i = 1 ; i <= V ; ++i)ady[i].clear();
	}
	
	return 0;
}
