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
 
 /**
INPUT:
1
5 100
20 15 30 80 100
* 
20 100 1 2 3 4 5
* 
101 20 1 2 3 4 5
* 
OUTPUT
65 3
  * */

int main(){
	
	TEST(t) {
		int a, b;
		sii(a, b);
		vi v(a);
		forn(i, a)si(v[i]);
		
		int i = 0;
		int j = 0;
		
		int sum = 0, cnt = 0;
		
		int elem = 0, ans = 0;
		
		while(j < a){
			if(sum + v[j] <= b) {
				sum += v[j];
				cnt++;
				j++;
				if(cnt > elem){
					elem = cnt;
					ans = sum;
				}
				else if(cnt == elem){
					ans = min(ans, sum);
				}
			}
			else {
				if(i == j)j++;
				else {
					cnt--;
					sum -= v[i];
				}
				i++;
			}
		}
		
		cout << ans << " " << elem << "\n";
	}
	
	return 0;
}
