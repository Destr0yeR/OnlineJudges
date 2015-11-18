#include<bits/stdc++.h>
#define MAX 101

using namespace std;

int V;
vector<int> graph[MAX];
int visited[MAX];

void reset(){
	memset(visited, 0, sizeof(visited));
}

void init(){
	reset();
	for(int i = 0 ; i <= V ; ++i)graph[i].clear();
}

int dfs(int from){
	visited[from] = 1;
	int tot = 0, sz = graph[from].size();
	
	for(int i = 0 ; i < sz ; ++i){
		if(visited[graph[from][i]] == 1)continue;
		tot += (dfs(graph[from][i])+1);
	}
	
	return tot;
}

int main(){
	int q, to;
	while(cin >> V){
		if(V == 0)break;
		init();
		for(int i = 1 ; i <= V ; ++i){
			cin >> q;
			while(q--){
				cin >> to;
				graph[i].push_back(to);
			}
		}
		int maxi = 0, ans = V, aux;

		for(int i = 1 ; i <= V ; ++i){
			reset();
			aux = dfs(i);
			//cout << i << " " << aux << endl;
			if(maxi < aux){
				maxi = aux;
				ans = i;
			}
			else if(maxi == aux){
				ans = min(ans, i);
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
