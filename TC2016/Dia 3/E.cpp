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

#define MAX (1<<31)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef complex<double> cd;

typedef vector<int> vi;
typedef vector<cd> vcd;

vi p;
vector<int> v;
map<int, int>b;

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};
typedef std::priority_queue<int,std::vector<int>,mycomparison> mypq_type;

void bfs(int x, int y){
	mypq_type q(mycomparison(true));
	int curr, next;
	q.push(1);
	
	while(!q.empty()){
		curr = q.top();
		q.pop();
		
		if(curr >= x)v.push_back(curr);
		
		forn(i, sz(p)){
			if(y/curr < p[i])break;
			next = p[i]*curr;
			
			if(b[next] == 0){
			    b[next] = 1;
				q.push(next);
			}
		}
	}
	while(!q.empty())q.pop();
}

bool isValid(){
	return true;
}

int A, B;

void dfs(int node, int par){
	b[node] = 1;
	if(node >= A)v.push_back(node);
	int next;
	
	for(int i = par ; i < sz(p) ; ++i){
		if(B/node < p[i])break;
		next = p[i] * node;
		if(b[next] == 0)dfs(next, i);
	}
}

int main(){
	int n, x, y;
	
	while(si(n) == 1){
		if(!n)break;
		p.clear();
		v.clear();
		b.clear();
		forn(i, n){si(x); p.push_back(x);}
		
		sii(x, y);
		A = x;
		B = y;
		
		dfs(1, 0);
		
		if(sz(v)){
			sort(all(v));
			forn(i, sz(v)){
				if(i)printf(",");
				printf("%d", v[i]);
				
			}
		}
		else printf("none");
		puts("");
	}
}
