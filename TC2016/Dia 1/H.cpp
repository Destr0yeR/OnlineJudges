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

#define MAX 1000006

bitset<MAX> b, vis;

int dx[] = {1, -1, 10, -10, 100, -100, 1000, -1000, 10000, -10000, 100000, -100000};

int n, x, ans;
void sieve(){
	b.set();
	b[0] = b[1] = 0;
	int sq = sqrt(MAX);
	for(int i = 4 ; i < MAX ; i+=2)b[i] = 0;
	for(int i = 3 ; i <= sq ; i+=2)if(b[i])for(int j = i ; i*j < MAX ; j+=2)b[i*j] = 0;
}

int Fix(int num, int off){
	
	int den = abs(dx[off]);
	int dir = (dx[off]>0?1:-1);
	
	int res = num%den, aux = (num/den)/10, tmp = (num/den)%10;
	
	tmp += dir;
	if(tmp == 10)tmp = 0;
	else if(tmp == -1)tmp = 9;
	
	return (aux*10*den + tmp*den + res);
}

typedef pair<int, int> node;
#define val first
#define lvl second

void bfs(){
	queue<node> q;
	q.push(make_pair(x, 0));
	node curr;
	int L = (n<<1), next;
	
	vis.reset();
	while(!q.empty()){
		curr = q.front();
		q.pop();
		vis[curr.val] = 1;
		
		forn(i, L){
			next = Fix(curr.val, i);
			if(vis[next] == 0){
				if(b[next]){
					ans = curr.lvl + 1;
					return;
				}
				if(curr.lvl != 3)q.push(make_pair(next, curr.lvl + 1));
			}
		}
	}
}

int main(){
	sieve();
	
	TEST(t){
		sii(n, x);
		ans = -1;
		if(b[x])ans = 0;
		else bfs();
		if(ans == -1)ans = 4;
		printf("%d\n", ans);
	}
}
