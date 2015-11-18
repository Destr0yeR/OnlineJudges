#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int T, n, k, p;
	scanf("%d", &T);
	
	for(int tc = 1 ; tc <= T ; ++tc){
		cin >> n >> k >> p;
		k = (k+p)%n;
		if(k==0)k=n;
		printf("Case %d: %d\n", tc, k);
	}
	
	return 0;
}
