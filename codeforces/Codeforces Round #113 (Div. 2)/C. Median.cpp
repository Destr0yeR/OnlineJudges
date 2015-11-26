#include<bits/stdc++.h>
#define MAX 502
#define INF (1<<30)

using namespace std;

int a[MAX];

int main(){
	int n, x, mid, ans;
	bool found = false;
	cin >> n >> x;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i];
		if(a[i] == x)found = true;
	}
	
	if(!found){
		a[n] = x;
		n++;
	}
	
	sort(a, a + n);
	
	mid = (n+1)/2 -1;
	
	ans = 0;
	if(a[mid] < x){
		ans = 1;
		if(n%2 == 1)ans++;
		for(int i = mid+1 ; i < n ; ++i){
			if(a[i] == x)break;
			ans += 2;
		}
	}
	else if(a[mid] > x){
		ans = 1;
		if(n%2 == 0)ans++;
		for(int i = mid-1 ; i >= 0 ; --i){
			if(a[i] == x)break;
			ans += 2;
		}
	}
	
	if(!found)ans++;
	
	cout << ans << endl;
	
	return 0;
}
