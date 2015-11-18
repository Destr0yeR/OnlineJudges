#include<bits/stdc++.h>
#define MAX 1001

using namespace std;

map<string, int> m;

void reset(){
	memset(visited, 0, sizeof(visited));
}

void init(){
	reset();
	
	for(int i = 0 ; i <= V ; ++i)graph[i].clear();
}

int word(string s){
	if(m.count(s) == 0)m[s] = m.size();
	return m[s];
}

void bfs(int from){
	queue<int> Q;
	
	q.push(from);
	
	while(!Q.empty()){
		
	}
}

int main(){
	int T;
	cin >> T;
	cout << "SHIPPING ROUTES OUTPUT" << endl;
	for(int tc = 1 ; tc <= T ; ++tc){
		cout << endl << "DATA SET " << tc << endl;
		cin >> V >> E >> p;
		init();
		
		for(int i = 0 ; i < E ; ++i){
			
		}
		
	}
	cout << endl;
	cout << "END OF OUTPUT" << endl;
	return 0;
}
