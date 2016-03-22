#include <bits/stdc++.h>

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)

#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define forr(i, a, b) for(int i = a ; i < b ; ++i)

#define sz(x) (int)x.size()

#define rforn(i, n) for(int i = n-1 ; i >= 0 ; --i)
#define rforr(i, a, b) for(int i = b-1 ; i >= a ; --i)

#define mset(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()

#define TEST(t) int T; cin >> T; for(int t = 1 ; t <= T ; ++t)

using namespace std;

#define MAX 101

int mat[MAX][MAX];
int col[MAX];
vector<int> ady[MAX];

int n;

bool dfs(int node){
    if(col[node])return true;
    bitset<5> cl;
    cl.reset();
    
    forn(i, sz(ady[node]))if(col[ady[node][i]] != 0)cl[col[ady[node][i]]] = 1;
    int i;
    for(i = 1; i <= 4; i++)
        if(cl[i] == 0)break;
    if(i == 5)return false;
    
    for(int c = 1; c <= 4; c++){
        if(cl[c] == 0){
            col[node] = c;
            bool fail = false;
            forn(i, sz(ady[node])){
                if(col[ady[node][i]]==0){
                    fail |= not dfs(ady[node][i]);
                    if(fail)break;
                }
			}
            if(fail==false)return true;
        }
	}
    col[node] = 0;
    return false;
}
int main(){
	int x, y;
	char c;
	si(n);
	mset(mat, 0);
	mset(col, 0);
	
	while(si(x) == 1){
		sc(c);
		si(y);
		if(mat[x][y] == 0){
			mat[x][y] = 1;
			if(x == y)continue;
			ady[x].push_back(y);
			ady[y].push_back(x);
		}
	}
	
    forr(i, 1, n+1)dfs(i);
    forr(i, 1, n+1)printf("%d %d\n", i, col[i]);

	return 0;
}

