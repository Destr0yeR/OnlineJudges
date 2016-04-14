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

#define MAX 10001

typedef long long ll;
typedef unsigned long long ull;

typedef complex<double> cd;

typedef vector<int> vi;
typedef vector<cd> vcd;

struct node{
	int i, c;
	node(){}
	node(int _i, int _c){i = _i; c = _c;}
};

vector<node> ady[MAX];

map<string, int> m;
map<int, string> rm;

int tot;

int index(string s){
	if(m.count(s) == 0){
		rm[tot] = s;
		m[s] = tot++;
	}
	return m[s];
}

bool cmp(node a, node b){
	return a.c > b.c;
}

int main(){
	int n, m, g, c;
	sii(n, m);
	string s;
	tot = 0;
	
	forn(i, n){
		cin >> s;
		sii(g, c);
		
		ady[g].push_back(node(index(s), c));
	}
	int len;
	
	forr(i, 1, m+1){
		sort(all(ady[i]), cmp);
		len = sz(ady[i]);
		if(len == 2){
			cout << rm[ady[i][0].i] << " " << rm[ady[i][1].i] << endl;
		}
		else{
			if(ady[i][1].c == ady[i][2].c) cout << "?\n";
			else cout << rm[ady[i][0].i] << " " << rm[ady[i][1].i] << "\n";
		}
	}
	
	return 0;
}

