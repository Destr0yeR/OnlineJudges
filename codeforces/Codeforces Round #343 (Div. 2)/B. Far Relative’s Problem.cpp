#include<bits/stdc++.h>

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)

#define mset(x, y) memset(x, y, sizeof(x))
#define all(v) v.begin(), v.end()

#define MAX 5001

using namespace std;

int m[MAX], f[MAX];

int main(){
	
	int n, a, b;
	si(n);
	char c;
	mset(f, 0);
	mset(m, 0);
	
	for(int i = 0; i < n; i++) {
		cin >> c >> a >> b;
		for(int j = a; j <= b; j++) {
			if (c == 'M') m[j]++;
			else f[j]++;
		}
	}
	int ans = 0;
	for(int i = 1; i < 380; i++) {
		if (ans < 2 * min(m[i], f[i])) {
			ans = 2 * min(m[i], f[i]);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
