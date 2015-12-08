#include<bits/stdc++.h>

#define MAX 1000001

using namespace std;

bitset<MAX> b;

int arr[MAX];

void sieve(){
	b.set();
	memset(arr, 0, sizeof(arr));
	int sq = sqrt(MAX);
	
	b[0] = b[1] = 0;
	
	for(int i = 4 ; i < MAX ; i+=2)b[i] = 0;
	
	for(int i = 3 ; i <= sq ; i+=2)if(b[i] == 1)for(int j = i ; j * i < MAX ; j+=2)b[i*j] = 0;
	
	for(int i = 1 ; i < MAX ; i++){
		if(b[i] == 1)arr[i] = arr[i-1] + 1;
		else arr[i] = arr[i-1];
	}
}

int main(){
	sieve();
	int a, b, k, ans = INT_MAX;
	
	cin >> a >> b >> k;
	
	int sz = b - a + 1, sup, mid, l = 1;
	while(l <= sz){
		
		mid = (l+sz)/2;
		
		sup = b - mid + 1;
		bool posible = true;
		for(int x = a ; x <= sup ; ++x){
			if(arr[x+mid-1] - arr[x-1] < k){
				posible = false;
				break;
			}
		}
		if(posible){
			ans = min(ans, mid);
			sz = mid-1;
		}
		else l = mid+1;
	}
	
	if(ans == INT_MAX) cout << "-1\n";
	else cout << ans << "\n";
	
	return 0;
}
