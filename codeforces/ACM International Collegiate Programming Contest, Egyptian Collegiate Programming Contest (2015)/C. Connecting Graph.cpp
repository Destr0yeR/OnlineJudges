#include<bits/stdc++.h>
#define MAX 100005

using namespace std;

int padre[MAX];
int ans[MAX];


struct Edge{
	int x, y, t;
	Edge(int _x, int _y){x = _x; y = _y;}
};

int Find(int x){
	if(padre[x] == x)return x;
	return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
	padre[Find(x)] = y;
}

void Split(int x, int y){
	int p = x;
	while(padre[p] != y){
		if(padre[p] == p)break;
		p = padre[p];
	}
	
	if(p == padre[p]){
		p = y;
		while(padre[p] != x){
			if(padre[p] == p)break;
			p = padre[p];
		}
		padre[p] = p;
	}
}

int main(){
	int T;
	cin >> T;
	
	while(T--){
		for(int i = 0 ; i < MAX ; ++i)padre[i] = i;
		
		
	}
	return 0;
}
