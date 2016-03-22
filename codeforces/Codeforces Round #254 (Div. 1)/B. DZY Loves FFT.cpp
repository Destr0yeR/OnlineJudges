#include <bits/stdc++.h>

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)

#define sz(x) (int)x.size()

#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define forr(i, a, b) for(int i = a ; i < b ; ++i)

#define rforn(i, n) for(int i = n-1 ; i >= 0 ; --i)
#define rforr(i, a, b) for(int i = b-1 ; i >= a ; --i)

#define mset(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()

#define TEST(t) int T; cin >> T; for(int t = 1 ; t <= T ; ++t)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll x;
int n, d;

vi a, b, lb;

ll getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB(){
    forn(i, n)a[i] = i + 1;
    forn(i, n)swap(a[i], a[getNextX() % (i + 1)]);
    forn(i, n)b[i] = ((i < d)?1:0);
    forn(i, n)swap(b[i], b[getNextX() % (i + 1)]);
}

int main(){
	si(n);
	si(d);
	cin >> x;
	
	a.resize(n);
	b.resize(n);
	lb.resize(n);
	initAB();
	
	int l = n;
	
	rforn(i, n){
		if(b[i] == 1)l = i;
		lb[i] = l;
	}
	
	int curr;
	
	forn(i, n){
		curr = lb[0];
		if(curr > i)puts("0");
		else{
			printf("%d\n", a[i-curr]);
		}
	}
	
	return 0;
}



