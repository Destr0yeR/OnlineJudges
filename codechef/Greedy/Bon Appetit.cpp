/*#include<bits/stdc++.h>

#define MAX 100005

using namespace std;

typedef long long ll;

map<int, int> m;
vector<int> v[MAX];

struct par{
	int s, f;
}c[MAX];

bool cmp(int a, int b){
	return c[a].f < c[b].f;
}

int main(){
	int T, n, k, tot, end, _c, cont, sz, s, f;
	scanf("%d", &T);
	
	while(T--){
		scanf("%d %d", &n, &k);
		cont = 0;
		m.clear();	
		
		for(int i = 0 ; i < n ; ++i){
			scanf("%d %d %d", &s, &f, &_c);
			c[i].s = s;
			c[i].f = f;
			if(m.find(_c) == m.end())m[_c] = cont++;
			v[m[_c]].push_back(i);
		}
		
		for(int i = 0 ; i < cont ; ++i)sort(v[i].begin(), v[i].end(), cmp);
		
		tot = 0;
		
		for(int i = 0 ; i < cont ; ++i){
			end = -1;
			sz = v[i].size();
			for(int j = 0 ; j < sz ; ++j){
				if(c[v[i][j]].s >= end){
					tot++;
					end = c[v[i][j]].f;
				}
			}
		}
		
		printf("%d\n", tot);
		for(int i = 0 ; i < cont ; ++i)v[i].clear();
	}
	
	return 0;
}*/


#include<bits/stdc++.h>
 
#define MAX 100005
 
using namespace std;
 
typedef long long ll;
 
struct customer{
	int s, f, c;
	customer(){}
	customer(int _s, int _f, int _c){s=_s;f=_f;c=_c;}
}c[MAX];
 
bool cmp(customer a, customer b){
	if(a.c == b.c){
		return a.f < b.f;
	}
	return a.c > b.c;
}
 
int main(){
	int T, n, k, tot, last, end;
	scanf("%d", &T);
	
	while(T--){
		scanf("%d %d", &n ,&k);
		
		for(int i = 0 ; i < n ; ++i){
			scanf("%d %d %d", &c[i].s, &c[i].f, &c[i].c);
		}
		
		sort(c, c + n, cmp);
		
		tot = 0;
		last = -1;
		end = -1;
		
		for(int i = 0 ; i < n ; ++i){
			if(last != c[i].c){
				tot++;
				last = c[i].c;
				end = c[i].f;
			}
			else{
				if(c[i].s >= end){
					tot++;
					end = c[i].f;
				}
			}
		}
		
		printf("%d\n", tot);
	}
	
	return 0;
}
