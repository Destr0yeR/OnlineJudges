#include<bits/stdc++.h>

using namespace std;

int r[10];

int main(){
	string s;
	
	while(cin >> s){
		bool cg;
		int sz = s.size(), curr;
		memset(r, 0, sizeof(r));
		
		for(int i = 0 ; i < sz ; ++i){
			curr = s[i] - '0';
			
			cg = false;
			
			while(curr >= 0 && r[curr] >= 2){
				curr--;
				cg = true;
			}
			
			if(!cg){
				r[curr]++;
			}
			else{
				s[i] = curr + '0';
				
				for(int j = i+1 ; j < sz ; ++j){
					s[j] = '9';
				}
				if(curr == -1){
					s[i] = '9';
					i--;
					
					r[s[i]-'0']--;
					while(s[i] == '0'){
						s[i] = '9';
						i--;
						r[s[i]-'0']--;
					}
					
					s[i]--;
					i--;
				}
				else r[curr]++;
			}
			
			
		}
		int i = 0;
		
		while( s[i] == '0')i++;
		
		for( ; i < sz ; ++i)cout << s[i];
		
		cout << endl;
	}
}
