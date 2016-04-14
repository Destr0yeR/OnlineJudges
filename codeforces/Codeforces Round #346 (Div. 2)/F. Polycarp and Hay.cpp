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

#define MAX 1001

int mat[MAX][MAX];
int tmp[MAX][MAX];
int vis[MAX][MAX];

struct node{
	int i, j, v;
	node(){}
	node(int _i, int _j, int _v){i = _i; j = _j; v = _v;}
};

int dx[] = {1, -1,  0, 0};
int dy[] = {0,  0, -1, 1};

int n, m;
bool isValid(int i, int j){
	if(i < 0 || i >= n)return false;
	if(j < 0 || j >= m)return false;
	return true;
}
int cnt, tot;

void dfs(int x, int y, int val){
	if(tot == cnt)return;
	tmp[x][y] = 1;
	vis[x][y] = 1;
	tot++;
	int X, Y;
	forn(i, 4){
		X = x + dx[i];
		Y = y + dy[i];
		if(!isValid(X, Y))continue;
		if(tmp[X][Y] == 1)continue;
		if(mat[X][Y] < val)continue;
		dfs(X, Y, val);
	}
}

vector<node> a;

bool cmp(node a, node b){
	return a.v < b.v;
}

int main(){
	ll k;
	
	sii(n, m);
	sll(k);
	
	forn(i, n)forn(j, m){
		si(mat[i][j]);
		a.push_back(node(i, j, mat[i][j]));
	}
	
	sort(all(a), cmp);
	
	int len = sz(a);
	int min;
	bool posible = false;
	forn(i, len){
		if(k%a[i].v == 0){
			if(len-i >= k/a[i].v){
				min = a[i].v;
				cnt = k/a[i].v;
				if(vis[a[i].i][a[i].j])continue;
				mset(tmp, 0);
				tot = 0;
				dfs(a[i].i, a[i].j, a[i].v);
				if(cnt == tot){
					posible = true;
					break;
				}
			}
		}
	}
	
	if(posible){
		puts("YES");
		forn(i,n){
			forn(j,m){
				if(j)printf(" ");
				if(cnt){
					if(tmp[i][j]){
						printf("%d", min);
						cnt--;
					}
					else printf("0");
				}
				else printf("0");
			}
			puts("");
		}
	}
	else puts("NO");
	
	return 0;
}
