#include<bits/stdc++.h>

#define MAX 100005

using namespace std;

bitset<MAX> v, b, vb;
queue<int> Q;


int key[MAX];
int door[MAX];

vector<int> ady[MAX];

void reset(){
	v.reset();
	b.reset();
	vb.reset();
	
	for(int i = 0 ; i < MAX; ++i){
		key[i] = 0;
		door[i] = 0;
		ady[i].clear();
	}
	
	while(!Q.empty())Q.pop();
}

void bfs(int n){
	bool posible = false, go;
	int curr, sz, x;
	
	Q.push(1);
	
	while(!Q.empty()){
		curr = Q.front();
		Q.pop();
		
		if(v[curr] == 1)continue;
		
		v[curr] = 1;
		go = true;
		
		if(curr == n){
			posible = true;
			break;
		}
		
		sz = ady[curr].size();
		
		if(key[curr]){
			if(!b[key[curr]]){
				vb[curr] = 1;
				v[curr] = 0;
				go = false;
			}
		}
		else if(door[curr]){
			b[curr] = 1;
			if(vb[door[curr]] == 1){
				Q.push(door[curr]);
			}
		}
		
		if(go){
			for(int i = 0 ; i < sz ; ++i){
				x = ady[curr][i];
				if(v[x] == 0)Q.push(x);
			}
		}
	}
	
	
	if(posible)printf("Y\n");
	else printf("N\n");
}

int main(){
	int n, k, m, d, l, x, y;
	
	while(scanf("%d %d %d", &n, &k, &m) == 3){
		if(n == -1 && k == -1 && m == -1)break;
		
		reset();
		
		for(int i = 0 ; i < k ; ++i){
			scanf("%d %d", &l, &d);
			key[d] = l;
			door[l] = d;
		}
		
		for(int i = 0 ; i < m ; ++i){
			scanf("%d %d", &x, &y);
			ady[x].push_back(y);
			ady[y].push_back(x);
		}
		
		bfs(n);
	}
	
	return 0;
}
