#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int T;
	
	double d, u , v;
	
	cin >> T;
	
	for(int tc = 1 ; tc <= T ; ++tc){
		cin >> d >> v >> u;
		
		if(v >= u || u == 0 || v == 0){
			printf("Case %d: can't determine\n",tc);
		}
		else{
			double ans;
			
			ans = fabs(d/sqrt(u*u - v*v) - d/u);
			
			printf("Case %d: %.3f\n",tc,ans);
		}
	}
	
	return 0;
}
