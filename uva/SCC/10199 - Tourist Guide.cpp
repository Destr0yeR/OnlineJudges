#include<bits/stdc++.h>
#define MAX 101

using namespace std;

int V, E, disc;
vector<int> ady[MAX];
vector<int> ap;
map<string, int>m;
int parent[MAX];
int dist[MAX];
int visited[MAX];
int low[MAX];
int used[MAX];
string cit[MAX];

void init(){
	disc = 0;
	for(int i = 0 ; i <= V ; ++i){
		ady[i].clear();
		visited[i] = 0;
		parent[i] = -1;
		used[i] = 0;
	}
	ap.clear();
	m.clear();
}

void dfs(int from){
	visited[from] = 1;
	dist[from] = low[from] = disc++;
	int to, sz, child = 0;
	
	sz = ady[from].size();
	for(int i = 0 ; i < sz ; ++i){
		to = ady[from][i];
		if(visited[to] == 0){
			parent[to] = from;
			child++;
			dfs(to);
			
			low[from] = min(low[to], low[from]);
			
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

int main(){
	int tc = 1, sz;
	string s, a, b;
	while(cin >> V){
		if(V==0)break;
		if(tc != 1)cout << endl;
		init();
		
		for(int i =  1 ; i <= V ; ++i){
			cin >> s;
			m[s] = i;
			cit[i] = s;
		}
		
		cin >> E;
		
		for(int i = 0 ; i < E ; ++i){
			cin >> a >> b;
			ady[m[a]].push_back(m[b]);
			ady[m[b]].push_back(m[a]);
		}
		
		for(int i = 1 ; i <= V ; ++i){
			if(visited[i] == 0)dfs(i);
		}
		
		sz = ap.size();
		
		cout << "City map #" << tc++ << ": " << sz << " " << "camera(s) found" << endl;
		
		vector<string> ans;
		
		for(int i = 0 ; i < sz ; ++i){
			ans.push_back(cit[ap[i]]);
		}
		
		sort(ans.begin(), ans.end());
		
		for(int i = 0 ; i < sz ; ++i){
			cout << ans[i] << endl;
		}
	}
	
	return 0;
}
