#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

int padre[101];

int Find(int x){
	if(x == padre[x]) return x;
	return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
	padre[Find(x)] = Find(y);
}

struct Edge{
	int x, y, d;
}arista[1001];

bool cmp(Edge a, Edge b){
	return a.d < b.d;
}

void init(int x){
	for(int i = 0 ; i <= x ; ++i)padre[i] = i;
}

int main()
{
	int c, s, q, x, y, d, maxi, f, t;
	for(int tc = 1; ; ++tc){
		scanf("%d %d %d", &c, &s, &q);
		if(c == 0 && s == 0 && q == 0)return 0;
		if(tc != 1)printf("\n");
		printf("Case #%d\n", tc);
		for(int i = 0; i < s ; ++i){
			scanf("%d %d %d", &arista[i].x, &arista[i].y, &arista[i].d);
		}
		sort(arista, arista + s, cmp);
		for(int i = 0 ; i < q ; ++i){
			maxi = 0;
			init(c);
			scanf("%d %d", &f, &t);
			for(int j = 0 ; j < s ; ++j){
				x = arista[j].x;
				y = arista[j].y;
				d = arista[j].d;
				if(Find(x) != Find(y)){
					Union(x, y);
					maxi = d;
					if(Find(f) == Find(t))break;
				}
			}
			if(Find(f) != Find(t))printf("no path\n");
			else printf("%d\n", maxi);
		}
		
	}
}