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

class SegmentTree {
	struct node {
		int l, r;
		int value;
		node():l(-1), r(-1), value(0){}
		node(int l, int r, int value):l(l),r(r),value(value){}
		node(int value):l(-1),r(-1),value(value){}
		node merge(const node &a,const node &b){
			return node(a.value + b.value);
		}
	};
	private:		
		vector<int> A;
		vector<node> tree;
	public:
		void init(const vector<int>& values) {
			A = values;
			int szA = sz(A)*2, szN = 1;
			while(szN < szA)szN <<= 1;
			tree.resize(szN);
			
			build(1, 0, sz(A)-1);
		}
		node build(int current, int l, int r) {
			if(l == r) {
				tree[current] = node(l, r, A[l]);
				return tree[current];
			}
			int mid = l+(r-l)/2;
			node nodeLeft 	= build(current*2, l, mid);
			node nodeRight 	= build(current*2 + 1, mid+1, r);
			
			return tree[current] = node(l, r, 0).merge(nodeLeft, nodeRight);
		}
		void update() {
		}
		node query(int current, int l, int r, int qL, int qR){
			cout << "current: " << current << endl;
			if(qL <= l && r <= qR) return tree[current];
			if(qL > r || l > qR) return node();
			cout << current << endl;
			
			int mid = l + (r-l)/2;
			node nodeLeft 	= query(current*2, l, mid, qL, qR);
			node rightLeft	= query(current*2+1, mid+1, r, qL, qR);
			
			return node().merge(nodeLeft, rightLeft);
		}
		int queryValue(int qL, int qR) {
			return query(1, 0, sz(A)-1, qL, qR).value;
		}
};

int main(){
	SegmentTree st;
	
	vector<int> A = {1, 1, 3, 4, 5, 6, 7};
	
	st.init(A);
	
	cout << st.queryValue(0, 200) << endl;
}
