#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int padre[101];
int sets;

int Find(int x){
	if(x == padre[x]) return x;
	return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
	padre[Find(x)] = Find(y);
	sets--;
}

struct Edge{
	int x, y, d;
}arista[10001];

bool cmp(Edge a, Edge b){
	return a.d > b.d;
}

void init(int x){
	for(int i = 0 ; i <= x ; ++i)padre[i] = i;
	sets = x;
}

int main(){
	int T, n, m, total, x, y, d;
	scanf("%d", &T);
	for(int tc = 1 ; tc <= T ; ++tc){
		scanf("%d %d", &n, &m);
		init(n);
		for(int i = 0 ; i < m ; ++i){
			scanf("%d %d %d", &arista[i].x, &arista[i].y, &arista[i].d);
		}
		total = 0;
		sort(arista, arista + m, cmp);

		for(int i = 0 ; i < m ; ++i){
			x = arista[i].x;
			y = arista[i].y;
			d = arista[i].d;
			if(Find(x) != Find(y)){
				Union(x, y);
				total = d;
			}
		}

		printf("Case #%d: %d\n", tc, total);
	}
}