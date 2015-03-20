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
}arista[10500];

bool cmp(Edge a, Edge b){
	return a.d < b.d;
}

void init(int x){
	for(int i = 0 ; i <= x ; ++i)padre[i] = i;
	sets = x;
}

int main(){
	int T, n, m, total, _total, x, y, d, mini;
	bool usado;
	scanf("%d", &T);
	for(int tc = 1 ; tc <= T ; ++tc){
		scanf("%d %d", &n, &m);
		
		vector<int> v(0);
		vector<int>::iterator it;
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
				v.push_back(d);
				total += d;
			}

			if(sets == 1)break;
		}

		if(m > n-1){
			mini = 2147483647;
			for(it = v.begin() ; it != v.end() ; ++it){
				usado = false;
				init(n);
				_total = 0;

				for(int i = 0 ; i < m ; ++i){
					x = arista[i].x;
					y = arista[i].y;
					d = arista[i].d;

					if(Find(x) != Find(y)){
						if(!usado){
							if(d == (*it)){
								usado = true;
							}
							else{
								Union(x, y);
								_total += d;
							}
						}
						else{
							Union(x, y);
							_total += d;
						}
					}
					if(sets == 1)break;
				}

				if(sets==1){if(_total < mini)mini = _total;}
			}
			_total = mini;
		}
		else{
			_total = total;
		}
		printf("%d %d\n", total, _total);
	}

	return 0;
}