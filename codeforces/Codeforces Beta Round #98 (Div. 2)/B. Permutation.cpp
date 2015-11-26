#include<bits/stdc++.h>

#define MAX 5001

using namespace std;

int main(){
	
	int n, aux, tot = 0;
	bitset<MAX> v;
	
	scanf("%d", &n);
	v.reset();
	
	for(int i = 1 ; i <= n; ++i){
		scanf("%d", &aux);
		v[aux] = 1;
	}
	
	for(int i = 1 ; i <= n ; ++i)if(v[i] == 1)tot++;
	
	printf("%d\n", n-tot);
	
	
	return 0;
}
