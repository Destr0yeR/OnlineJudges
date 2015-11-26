#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

typedef long long ll;

int a[MAX];

int main()
{
	int n, d;
	cin >> n >> d;
	for(int i = 0 ; i < n ; ++i) cin >> a[i];
	
	ll tot = 0, aux;
	int l, r, j;
	
	for(int i = 0 ; i < n ; ++i)
	{
		l = a[i];
		r = l + d;
		j = upper_bound(a, a+n, r) - a;
		aux = j - i - 1;
		aux = (aux * (aux - 1))/2;
		tot += aux;
	}
	cout << tot << endl;
	return 0;

}
