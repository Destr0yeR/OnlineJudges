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
}arista[201];

bool cmp(Edge a, Edge b){
	return a.d < b.d;
}

void init(int x){
	for(int i = 0 ; i <= x ; ++i) padre[i] = i;
	sets = x;
}



int main(){
	int T, v, e, total, x, y, d,mini;
	bool usado, encontrado;
	scanf("%d", &T);

	for(int tc = 1 ; tc <= T ; ++tc){
		scanf("%d %d", &v, &e);
		for(int i =  0 ; i < e ; ++i){
			scanf("%d %d %d", &arista[i].x, &arista[i].y, &arista[i].d);
		}
		sort(arista, arista + e, cmp);

		init(v);
		vector<int> ve(0);
		vector<int>::iterator it;
		for(int i = 0 ; i < e ; ++i){
			x = arista[i].x;
			y = arista[i].y;
			d = arista[i].d;
			if(Find(x) != Find(y)){
				Union(x, y);
				ve.push_back(i);
			}
			if(sets == 1)break;
		}

		printf("Case #%d : ", tc);
		if(sets > 1){
			printf("No way\n");
		}
		else{
			mini = 2147483647;
			encontrado = false;
			for(it = ve.begin(); it != ve.end() ; ++it){
				usado = false;
				init(v);
				total = 0;
				for(int i = 0 ; i < e ; ++i){
					x = arista[i].x;
					y = arista[i].y;
					d = arista[i].d;
					if(i != *it){
						if(Find(x) != Find(y)){
							Union(x, y);
							total += d;
						}
					}
					if(sets == 1)break;
				}
				if(sets == 1){
					encontrado = true;
					if(total < mini) mini = total;
				}
			}
			if(encontrado){
				printf("%d\n", mini);
			}
			else{
				printf("No second way\n");
			}
		}
	}
}