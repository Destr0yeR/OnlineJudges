#include<bits/stdc++.h>

using namespace std;

int main(){
	
	double x, y, z;
	int tc = 1;
	
	while(cin >> z >> x){
		if(z == 0 && x == 0)break;
		if(z>x){
			y = ceil((z/x)-1);
		}
		else
		{
			y = 0;
		}
		
		
		if(y > 26){
			printf("Case %d: impossible\n", tc++);
		}
		else
		{
			printf("Case %d: %.0f\n", tc++, y);
		}
		
	}
	
	return 0;
}
