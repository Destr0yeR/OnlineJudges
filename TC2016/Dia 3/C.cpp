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

#ifdef ONLINE_JUDGE
	#define sll(x) scanf("%I64d", &x)
#else
	#define sll(x) cin >> x
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef complex<double> cd;

typedef vector<int> vi;
typedef vector<cd> vcd;

#define MAX 102

int mat[MAX][MAX], nmat[MAX][MAX], vis[MAX][MAX];
int acu[MAX][MAX];

int dx[] = {-1, 0, 1, 0};
int dy[] = { 0,-1, 0, 1};

bool isValid(int x, int y){
	if(x < 0 || x > 101)return false;
	if(y < 0 || y > 101)return false;
	if(nmat[x][y] == 1)return false;
	if(mat[x][y] == 1)return false;
	return true;
}

bool isValid2(int x, int y){
	if(x < 0 || x > 101)return false;
	if(y < 0 || y > 101)return false;
	if(vis[x][y] == 1)return false;
	return true;
}

void dfs(int x, int y){
	nmat[x][y] = 1;
	int X, Y;
	
	for(int i = 0 ; i < 4 ; ++i){
		X = x + dx[i];
		Y = y + dy[i];
		if(isValid(X, Y))dfs(X, Y);
	}
}

void dfs2(int x, int y){
	vis[x][y] = 1;
	int X, Y;
	
	for(int i = 0 ; i < 4 ; ++i){
		X = x + dx[i];
		Y = y + dy[i];
		if(isValid2(X, Y)){
			if(nmat[X][Y] == 1)dfs2(X, Y);
			else acu[x][y]++;
		}
	}
}

int main(){
	int v;
	si(v);
	int x, y;
	
	forn(i, MAX)forn(j, MAX)vis[i][j] = nmat[i][j] = mat[i][j] = acu[i][j] = 0;
	
	forn(i, v){
		sii(x, y);
		mat[x][y] = 1;
	}
	dfs(0, 0);
	dfs2(0, 0);
	
	int tot = 0;
	forn(i, 102)forn(j, 102)tot += acu[i][j];
	
	cout << tot << endl;
}
