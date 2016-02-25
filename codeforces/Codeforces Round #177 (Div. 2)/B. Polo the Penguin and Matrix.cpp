#include<bits/stdc++.h>

#define MAX 101
#define D_MAX 1005

using namespace std;

typedef long long ll;

vector<int> v;

int main(){
	
	int n, m, d, x, ans;
		
	bool posible = true;
	
	scanf("%d %d %d", &n, &m, &d);
	
	for(int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> x;
			v.push_back(x);
			if(abs(v[0] - x)%d != 0)posible = false;
		}
	}
	
	if(posible){
		int sz = v.size(), mid;
		ans = 0;
		mid = sz/2;
		sort(v.begin(), v.end());
		
		for(int i = 0 ; i < sz ; ++i){
			ans += abs(v[i] - v[mid])/d;
		}
		
		printf("%d\n", ans);
	}
	else{
		printf("-1\n");
	}
	
	return 0;
}
