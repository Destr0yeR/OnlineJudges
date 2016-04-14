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

typedef complex<long double> cd;

typedef vector<int> vi;
typedef vector<cd> vcd;

const double PI = 4*atan(1);
const double TPI = 2*PI;

#define MAX 500001

vi d;

void fft(vcd &a, bool invert){
	int n = sz(a), bit, mid;
	cd wlen, w, u, v;
	double angle;
	
	for(int i = 1, j = 0 ; i < n ; ++i){
		bit = n >> 1;
		for( ; j >= bit ; bit >>= 1)j -= bit;
		j += bit;
		if(i < j) swap(a[i], a[j]);
	}
	
	for(int len = 2 ; len <= n ; len <<= 1){
		angle = TPI / len * (invert?-1:1);
		wlen = cd(cos(angle), sin(angle));
		mid = len >> 1;
		for(int i = 0 ; i < n ; i+=len){
			w = cd(1, 0);
			forn(j, mid){
				u = a[i + j];
				v = w * a[i + j + mid];
				a[i + j]  = u + v;
				a[i + j + mid] = u - v;
				w *= wlen;
			}
		}
	}
	
	if(invert)forn(i, n)a[i] /= n;
}

void process(){
	d.resize(MAX);
	fill(all(d), 0);
	forr(i, 1, MAX)for(int j = i; j < MAX ; j += i)d[j]++;
}

vi go(int n, vi x){
	x.resize(n);
	vcd a(all(x));
	
	int k = 1;
	while(k < n)k <<= 1;
	k <<= 1;
	
	a.resize(k);
	
	fft(a, false);
	forn(i, k)a[i] *= a[i];
	fft(a, true);
	
	vi res(k);
	forn(i, k)res[i] = int(a[i].real() + 0.5);
	
	return res;
}

struct Node{
	int left, right, value, index;
	Node(){}
	Node(int _left, int _right){left = _left; right = _right;}
	Node(int _left, int _right, int _value){left = _left; right = _right; value = _value;}
	Node(int _left, int _right, int _value, int _index){left = _left; right = _right; value = _value; index = _index;}
	
	void merge(const Node& lChild, const Node& rChild){
		int lv = lChild.value, rv = rChild.value;
		int li = lChild.index, ri = rChild.index;
		if(lv == rv){
			value = lv;
			index = min(li, ri);
		}
		else if(lv > rv){
			value = lv;
			index = li;
		}
		else{
			value = rv;
			index = ri;
		}
	}
	
};
ostream& operator<<(ostream& os, const Node& node){
	os << node.index << " " << node.value;
	return os;
}
Node tree[1 << 21];

vi res;

void build(int node, int l, int r){
	if(l == r){
		tree[node] = Node(l, r, res[l], l);
		return;
	}
	int lChild = node << 1, rChild = lChild + 1, mid = (l+r)>> 1;
	
	build(lChild, l, mid);
	build(rChild, mid + 1, r);
	
	tree[node].merge(tree[lChild], tree[rChild]);
}

Node query(int node, int l, int r, int i, int j){
	if(l >= i && r <= j){
		return tree[node];
	}
	if(l > j || r < i)return Node(0, 0, 0, MAX);
	
	int lChild = node << 1, rChild = lChild + 1, mid = (l+r) >> 1;
	
	Node x = query(lChild, l, mid, i, j);
	Node y = query(rChild, mid+1, r, i, j);

	Node tmp = Node(0, 0, 0, MAX);
	
	tmp.merge(x, y);
	return tmp;
}


void query_value(int i, int j){
	int n = MAX; 
	cout << query(1, 0, n-1, i, j) << endl;
}

void init_segment_tree(){
	int n = MAX;
	build(1, 0, n-1);
}

int main(){
	int l, r;
	
	process();
	res = go(MAX, d);
	init_segment_tree();
	
	TEST(t){
		sii(l, r);
		query_value(l, r);
	}

	return 0;
}

