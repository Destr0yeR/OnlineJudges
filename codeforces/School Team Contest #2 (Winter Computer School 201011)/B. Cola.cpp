#include<bits/stdc++.h>

using namespace std;

int n, a, b, c, x, y, z, ans;

int u[15000];


int main(){
	cin >> n >> a >> b >> c;
	ans = 0;
	memset(u, 0, sizeof(u));
	for(x = 0 ; x <= a ; x+=2){
		for(y = 0 ; y<= b; ++y){
			z = (n - (x*0.5 + y))/2;
			if((z*2 + y + floor(x*0.5)) != n)continue;
			if(z >= 0 && z <= c){
				if(u[x+y+z] == 0){
					ans++;
				}
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
