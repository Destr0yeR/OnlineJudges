#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	
	scanf("%d", &n);
	
	if(n <= 2)printf("-1\n");
	else{
		printf("%d", n);
		
		for(int i = n-1 ; i >= 1 ; --i)printf(" %d",i);
		printf("\n");
	}
	
	return 0;
}
