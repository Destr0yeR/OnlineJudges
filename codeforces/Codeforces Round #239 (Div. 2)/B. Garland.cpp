#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int a[30], b[30], sz, ans = 0;
	
	bool posible = true;
		
	string s1, s2;
	
	cin >> s1;
	cin >> s2;
	
	for(int i = 0 ; i < 30 ; ++i)b[i] = a[i] = 0;
	
	sz = s1.size();
	
	for(int i = 0 ; i < sz ; ++i){
		a[s1[i] - 'a']++;
	}
	
	sz = s2.size();
	
	for(int i = 0 ; i < sz ; ++i){
		if(a[s2[i] - 'a']){
			b[s2[i] - 'a']++;
		}
		else{
			posible = false;
			break;
		}
	}
	
	if(posible){
		ans = 0;
		for(int i = 0 ; i < 30 ; ++i){
			if(a[i] >= b[i]){
				ans += b[i];
			}
			else{
				ans += a[i];
			}
		}
		
		cout << ans << "\n";
	}
	else cout << "-1\n";

	return 0;
}
