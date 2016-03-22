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

int main(){
	int a, b;
	sii(a, b);
	int cnt = 0;
	while(a && b){
		if(a >= b){
			if(a == 1)break;
			b++;
			a -=2;
			if(b > 100)b = 100;
		}
		else{
			if(b == 1)break;
			a++;
			b -= 2;
			if(a > 100)a = 100;
		}
		cnt++;
	}
	
	printf("%d\n", cnt);
	
	return 0;
}



