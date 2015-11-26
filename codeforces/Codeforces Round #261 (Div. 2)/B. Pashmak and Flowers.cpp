#include<bits/stdc++.h>
#define MAX 200005

using namespace std;

unsigned long long a[MAX];

int main(){
	
	map<int, int> m;
	
	int n;
	unsigned long long maxi, mini, cmax = 0, cmin = 0;
	
	cin >> n;
	for(int i = 0 ; i < n ; ++i)cin >> a[i];
	
	
	sort(a, a + n);
	
	mini = a[0];
	maxi = a[n-1];
	
	for(int i = 0 ; ; ++i){
		if(mini != a[i])break;
		cmin ++;
	}
	
	for(int i = n-1 ; ; --i){
		if(maxi != a[i])break;
		cmax ++;
	}
	
	unsigned long long ans = cmax * cmin;
	
	if(maxi == mini)ans = (cmax*(cmin-1))/2;
	
	cout << maxi - mini << " " << ans << '\n';
	
	return 0;
}
