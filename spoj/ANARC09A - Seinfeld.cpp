#include<bits/stdc++.h>

using namespace std;

int main() {
	string s;
	int tc = 1;
	while(cin >> s){
		if(s[0] == '-')break;
		
		int ans = 0;
		int cnt = 0;
		
		for (int i = 0; i < (int)s.size(); i++)
		{
			if(s[i] == '{'){
				cnt++;
			}
			else {
				if(cnt <= 0){
					ans++;
					cnt++;
				}
				else {
					cnt--;
				}
			}
		}
		
		ans += (cnt/2);
		
		printf("%d. %d\n", tc++, ans);
	}
	
	return 0;
}
