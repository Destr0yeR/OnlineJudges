#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int T, x, k, q, p;
	
	scanf("%d", &T);
	
	while(T--){
		scanf("%d %d", &x, &k);
		
		q = x%k;
		p = k-q;
		
		printf("%d %d\n", p, q);
	}
	
	return 0;
}
