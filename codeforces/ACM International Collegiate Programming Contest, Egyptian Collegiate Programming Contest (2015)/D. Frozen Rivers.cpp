#include<bits/stdc++.h>

#define MAX 100005

using namespace std;

struct Node{
	int to;
	long long val;
	Node(){}
	Node(int _to, int _val){to = _to; val = _val;}
};

long long ans[MAX];

vector<long long> f;

vector<Node> ady[MAX];

void dfs(int x){
	int sz = ady[x].size(), to;
	long long val, s;
	if(sz == 0){
		f.push_back(ans[x]);
		return;
	}
	
	for(int i = 0 ;  i < sz ; ++i){
		val = ady[x][i].val;
		s = min(s, val);
	}
	
	for(int i = 0 ;  i < sz ; ++i){
		to = ady[x][i].to;
		val = ady[x][i].val;
		ans[to] = ans[x] + s + (val- s)*2;
		dfs(to);
	}
}

int main(){
	
	int T, n, from, q;
	long long val, p;
	cin >> T;
	
	while(T--){
		cin >> n;
		for(int i = 0 ; i < MAX ; ++i)ady[i].clear();
		f.clear();
		
		for(int i = 2 ; i <= n ; ++i){
			cin >> from >> val;
			ady[from].push_back(Node(i, val));
		}
		
		dfs(1);
		sort(f.begin(), f.end());
		
		vector<long long>::iterator up;
		
		cin >> q;
		for(int i = 0 ; i < q ; ++i){
			cin >> p;
			up = upper_bound (f.begin(), f.end(), p);
			cout << (up - f.begin()) << endl;
		}
	}
	
	return 0;
}
