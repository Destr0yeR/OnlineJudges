#include <bits/stdc++.h>

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)

#define sz(x) int(x.size())

#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define forr(i, a, b) for(int i = a ; i < b ; ++i)

#define rforn(i, n) for(int i = n-1 ; i >= 0 ; --i)
#define rforr(i, a, b) for(int i = b-1 ; i >= a ; --i)

#define mset(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()

#define TEST(t) int T; cin >> T; for(int t = 1 ; t <= T ; ++t)

using namespace std;

typedef complex<double> cd;
typedef vector<cd> vcd;
typedef vector<int> vi;
typedef long long ll;

using namespace std; 
using namespace std;

int dp[101][101];

struct node{
	int x, y, v;
	node(){}
	node(int x, int y, int v):x(x), y(y), v(v){}
	
	bool operator <(const node& b) const {
		return v < b.v;
	}
};

int r, c;

bool isValid(int x, int y){
	if(x < 0 || x >= r)return false;
	if(y < 0 || y >= c)return false;
	
	return true;
}

int dx[] = { 1,  0, -1, 0};
int dy[] = { 0, -1,  0, 1};

int main() {
	
	TEST(t) {
		string s;
		cin >> s;
		sii(r, c);
		int mat[r][c];
		
		vector<node> v;
		
		int ans = 0;
		
		forn(i, r)forn(j, c){
			int val;
			si(val);
			v.push_back(node(i, j, val));
			mat[i][j] = val;
		}
		
		sort(all(v));
		int x, y, X, Y;
		
		memset(dp, 0, sizeof(dp));
		
		forn(i, sz(v)){
			x = v[i].x;
			y = v[i].y;
			forn(j, 4){
				X = x + dx[j];
				Y = y + dy[j];
				
				if(isValid(X, Y) && mat[x][y] < mat[X][Y]){
					dp[X][Y] = max(dp[X][Y], dp[x][y] + 1);
				}
			}
		}
		
		forn(i, r)forn(j, c)ans = max(ans, dp[i][j]);
		
		cout << s << ": " << ans + 1 << endl;
	}
	
	return 0;
}
