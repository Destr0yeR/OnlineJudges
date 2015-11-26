#include<bits/stdc++.h>

using namespace std;

int a[101];

int main(){
	
	int n, x, y;
	
	scanf("%d", &n);
	
	for(int i = 1 ; i < n ; ++i)scanf("%d", &a[i]);
	
	scanf("%d %d", &x, &y);
	
	int acu = 0;
	
	for(int i = x ; i < y ; ++i)acu+=a[i];
	
	printf("%d\n", acu);
	
	return 0;
}
