#include<bits/stdc++.h>

#define MAX 2000005

using namespace std;

int cnt[MAX];
int a[MAX];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	memset(cnt, 0, sizeof(0));
	
	for(int i = 0 ; i < n ; ++i){
		scanf("%d", &a[i]);
		if(a[i] <= m)cnt[a[i]]++;
	}
	
	for(int i = m ; i >= 1 ; --i){
		if(cnt[i]){
			for(int j = 2 ; i * j <= m ; ++j){
				cnt[j*i] += cnt[i];
			}
		}
	}
	
	int tmp = 1, max = 0;
	long long aux = 1LL;
	
	for(int i = 0 ; i <= m ; ++i){
		if(cnt[i] > max){
			max = cnt[i];
			tmp = i;
		}
	}
	
	vector<int> ans;
	
	for(int i = 0 ; i < n ; ++i){
		if(tmp%a[i] == 0){
			ans.push_back(i);
			aux = (aux*a[i])/(__gcd(aux, (long long)a[i]));
		}
	}
	
	int sz = ans.size();
	
	cout << aux << " " << sz << '\n';
	
	if(sz){
		cout << ans[0] + 1;
		for(int i = 1 ; i < sz ; ++i){
			cout << " " << ans[i]+1;
		}
		cout << "\n";
	}
	
	return 0;
}
