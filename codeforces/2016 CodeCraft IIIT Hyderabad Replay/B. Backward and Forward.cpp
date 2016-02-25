#include<bits/stdc++.h>

#define MAX 100005

using namespace std;

int main(){
	
	int T, n, ans;
	long long a[MAX];
	
	scanf("%d", &T);
	
	while(T--){
		scanf("%d", &n);
		
		ans = 0;
		
		for(int i = 0; i < n ; ++i)cin >> a[i];
		
		int i = 0, j = n-1;
		
		while(i != j){
			if(a[i] != a[j]){
				if(a[i] > a[j]){
					a[j-1] += a[j];
					j--;
				}
				else{
					a[i+1] += a[i];
					i++;
				}
				ans++;
			}
			else{
				i++;
				j--;
				if(i > j)break;
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
