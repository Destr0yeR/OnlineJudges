#include <bits/stdc++.h>

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)

#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define forr(i, a, b) for(int i = a ; i < b ; ++i)

#define rforn(i, n) for(int i = n-1 ; i >= 0 ; --i)
#define rforr(i, a, b) for(int i = b-1 ; i >= a ; --i)

#define TEST(t) int T; cin >> T; for(int t = 1 ; t <= T ; ++t)

#define MAX 301
#define MAXS 2001

using namespace std;

int ka[MAX];

char path[MAX][MAX];
char text[MAXS][MAXS];

int m1, m2, n1, n2;

struct point{
	int x, y;
	point(){}
	point(int _x, int _y){x = _x; y = _y;}
	
	bool operator<(const point &b)const{
		if(x == b.x)return y < b.y;
		return x < b.x;
	}
};

vector<point> ans;

void kmp_array(char *x, int len){
	ka[0] = 0;
	
	for(int i = 1, j = 0 ; i < len ; ){
		if(x[i] == x[j])ka[i++] = ++j;
		else{
			if(j)j = ka[j-1];
			else ka[i++] = 0;
		}
	}
}

void kmp(char txt[][MAXS], char path[][MAX]){
	kmp_array(path[0], n2);
	ans.clear();
	bool posible;
	forn(k, m1 - n1 + 1){
		for(int i = 0, j = 0 ; i < m2 ; ){
			if(path[0][j] == txt[k][i]){
				i++;
				j++;
			}
			else{
				if(j == 0)i++;
				else j = ka[j-1];
			}
			if(j == n2){
				posible = true;
				for(int y = 1 ; y < n1 ; ++y){
					for(int x = 0 ; x < n2 ; ++x){
						if(path[y][x] != txt[k + y][i - n2 + x]){
							posible = false;
							break;
						} 
					}
					if(!posible)break;
				}
				if(posible)ans.push_back(point(k+1, i - n2 + 1));
				j = ka[j-1];
			}
		}
	}
	
	int sz = ans.size();
	if(sz){
		sort(ans.begin(), ans.end());
		forn(i, sz){
			printf("(%d,%d)\n", ans[i].x, ans[i].y);
		}
	}
	else puts("NO MATCH FOUND...");
}

int main(){
	char path[MAX][MAX];
	char text[MAXS][MAXS];
	
	sii(n1, n2);
	forn(i, n1)ss(path[i]);
	
	sii(m1, m2);
	forn(i, m1)ss(text[i]);
	
	kmp(text, path);

	return 0;
}

