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
struct point{
	int x, y;
};

vector<point> vp;

int main(){
	int n;
	si(n);
	vp.resize(n+1);
	forn(i, n+1){
		sii(vp[i].x, vp[i].y);
	}
	int ans = 0;
	forn(i, n-1){
		if(vp[i].x == vp[i+1].x){
			if(vp[i].y < vp[i+1].y){if(vp[i].x > vp[i+2].x)ans++;}
			else if(vp[i].x < vp[i+2].x)ans++;
		}
		else if(vp[i].y == vp[i+1].y){
			if(vp[i].x < vp[i+1].x){if(vp[i].y < vp[i+2].y)ans++;}
			else if(vp[i].y > vp[i+2].y)ans++;
		}
	}
	
	if(vp[n-1].x == vp[0].x){
		if(vp[n-1].y < vp[0].y){if(vp[n-1].x > vp[1].x)ans++;}
		else if(vp[n-1].x < vp[1].x)ans++;
	}
	else if(vp[n-1].y == vp[0].y){
		if(vp[n-1].x < vp[0].x){if(vp[n-1].y < vp[1].y)ans++;}
		else if(vp[n-1].y > vp[1].y)ans++;
	}
	
	printf("%d\n", ans);

	return 0;
}

