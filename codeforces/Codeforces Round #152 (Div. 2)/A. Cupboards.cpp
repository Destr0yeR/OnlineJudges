#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n, lo = 0, lc = 0, ro = 0, rc = 0, l, r;
	
	scanf("%d", &n);
	
	for(int i = 0 ; i < n; ++i){
		scanf("%d %d", &l, &r);
		if(l == 1)lo++;
		else lc++;
		if(r == 1)ro++;
		else rc++;
	}
	
	printf("%d\n", min(lo, lc) + min(rc, ro));
	
	return 0;
}
