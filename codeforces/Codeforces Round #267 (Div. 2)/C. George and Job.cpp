#include<bits/stdc++.h>

#define MAX_N 100005
#define MAX LLONG_MAX
#define MIN LLONG_MIN

using namespace std;

typedef long long ll;

ll a[MAX_N], l[MAX_N], r[MAX_N], t[MAX_N];

int main(){
	int n;
	
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	
	cin >> n;
	a[0] = MIN;
	for(int i = 1 ; i <= n ; ++i){
		cin >> a[i];
	}
	a[n+1] = MAX;
	l[0] = 0;
	r[n+1] = 0;
	
	for(int i = 1 ; i <= n ; ++i){
		l[i] = l[i-1] + ((a[i]<0)?0:1);
	}
	
	for(int i = n ; i >= 1; --i){
		r[i] = r[i+1] + ((a[i]>0)?0:1);
	}
	
	ll ans = MAX;
	for(int i = 2 ; i < n ; ++i){
		ans = min(ans, (l[i-1] + r[i+1] + ((a[i] == 0)?1:0)));
	}
	
	if(n == 2){
		ans = 0;
		if(a[1] >= 0)ans++;
		if(a[2] <= 0)ans++;
	}
	
	cout << ans << endl;

	return 0;
}
