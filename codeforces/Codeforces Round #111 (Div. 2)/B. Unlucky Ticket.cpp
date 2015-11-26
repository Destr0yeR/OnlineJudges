#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n, a[101], b[101];
	char c;
	
	cin >> n;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> c;
		a[i] = c-'0';
	}
	for(int i = 0 ; i < n ; ++i){
		cin >> c;
		b[i] = c-'0';
	}
	
	sort(a, a+n);
	sort(b, b+n);
	
	bool posible = true;
	bool less = false;
	
	
	if(a[0] == b[0])posible = false;
	if(a[0] < b[0])less = true;
	
	if(posible){
		if(less){
			for(int i = 1 ; i < n ; ++i){
				if(a[i] >= b[i]){
					posible = false;
					break;
				}
			}
		}
		else{
			for(int i = 1 ; i < n ; ++i){
				if(a[i] <= b[i]){
					posible = false;
					break;
				}
			}
		}
	}
	
	if(posible) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}
