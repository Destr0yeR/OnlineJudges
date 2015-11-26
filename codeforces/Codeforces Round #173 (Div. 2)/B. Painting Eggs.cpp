#include<bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(){
	
	int n, a, b, ta = 0;
	
	scanf("%d", &n);
	
	while(n--){
		scanf("%d %d", &a, &b);
		ta += a;
		if(ta < 500){
			printf("A");
		}
		else{
			ta-=1000;
			printf("G");
		}
	}
	printf("\n");
	
	return 0;
}
