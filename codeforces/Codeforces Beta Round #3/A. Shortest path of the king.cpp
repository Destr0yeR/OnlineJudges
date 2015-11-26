#include<bits/stdc++.h>

using namespace std;

int main(){
	string a, b;
	int dx, dy, H, V;
	
	cin >> a >> b;
	
	dx = b[0]-a[0];
	dy = b[1]-a[1];
	
	if(dx != 0){
		H = dx/abs(dx);
		dx = abs(dx);
	}
	else H = 0;
	
	if(dy != 0){
		V = dy/abs(dy);
		dy = abs(dy);
	}
	else V = 0;
	
	int maxi = max(dx, dy);
	
	printf("%d\n", maxi);
	
	for(int i = 1 ; i <= maxi ; ++i){	
		if(dx >= i){
			if(H == 1)printf("R");
			else printf("L");
		}
		if(dy >= i){
			if(V == 1)printf("U");
			else printf("D");
		}
		printf("\n");
	}
	
	return 0;
}
