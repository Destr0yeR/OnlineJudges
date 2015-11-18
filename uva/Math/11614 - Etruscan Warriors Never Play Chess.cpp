#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	
	double x, y;
	int T;
	
	cin >> T;
	
	while(T--){
		cin >> x;
		y = floor(sqrt(2*x+0.25) - 0.5);
		
		printf("%.f\n", y);
	}
	
	
	return 0;
}
