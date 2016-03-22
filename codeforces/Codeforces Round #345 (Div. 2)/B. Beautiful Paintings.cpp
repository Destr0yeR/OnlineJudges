#include <bits/stdc++.h>

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)

#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define forr(i, a, b) for(int i = a ; i < b ; ++i)

#define rforn(i, n) for(int i = n-1 ; i >= 0 ; --i)
#define rforr(i, a, b) for(int i = b-1 ; i >= a ; --i)

#define mset(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()

#define TEST(t) int T; cin >> T; for(int t = 1 ; t <= T ; ++t)

using namespace std;

int a[1001];
int cnt[1001];

int main(){
	int n, x, tot = 0;
	si(n);
	mset(cnt, 0);
	
	forn(i, n){
		si(x);
		if(!cnt[x])a[tot++] = x;
		cnt[x]++;
	}
	
	sort(a, a + tot);
	
	int ans = 0, aux;
	
	while(true){
		aux = -1;
		forr(i , 1, 1001){
			if(cnt[i]){
				aux ++;
				cnt[i]--;
			}
		}
		if(aux < 0)break;
		ans += aux;
	}
	
	printf("%d\n", ans);
	
	return 0;
}



