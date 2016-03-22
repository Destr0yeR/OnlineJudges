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

#define MAX 1000005

typedef long long ll;

ll L[MAX];
ll R[MAX];

int main(){
	int n, a, b, t;
	char c[MAX];
	
	sii(n, a);sii(b, t);
	ss(c);
	
	L[0] = R[0] = 1 + (c[0]=='w'?b:0);
	R[n] = 0;
	
	forr(i, 1, n)L[i] = (L[i-1] + 1 + (c[i] == 'w'?b:0)) + a;
	rforr(i, 1, n) R[i] = (R[i+1] + 1 + (c[i] == 'w'?b:0)) + a;
	
	if(L[n-1] <= t){
		printf("%d\n", n);
		return 0;
	}
	if(L[0] > t){
		puts("0");
		return 0;
	}
	
	int i = -1, j = n+1;
	while(L[i + 1] <= t)i++;
	while(L[0] + R[j - 1] <= t)j--;
	
	if(i == -1 && j == n + 1){
		puts("0");
		return 0;
	}
	if(i == -1){
		printf("%d\n", n-j + 1);
		return 0;
	}
	if(j == n+1){
		printf("%d\n", i + 1);
		return 0;
	}
	
	int ans = 0;
	int tmp = j;
	
	j = n;
	ans = max(i + 1, n - j + 1);
	
	while(i > 0){
		while(L[i] + R[j-1] + i * a <= t)j--;
		ans = max(ans, i + n - j + 1);
		i--;
	}

	j = tmp;
	i = 0;
	while(j < n){
		while(L[i+1] + R[j] + (n-j) * a <= t)i++;
		ans = max(ans, i + n - j + 1);
		j++;
	}
	
	cout << ans << endl;
	
	return 0;
}



