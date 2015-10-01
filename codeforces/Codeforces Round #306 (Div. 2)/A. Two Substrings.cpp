#include<bits/stdc++.h>

using namespace std;

int main(){
	
	string s;
	
	cin >> s;
	bool existA = false;
	bool existB = false;
	
	for(int i = 0 ; i < s.size()-1 ; ++i){
		if(s[i] == 'A' && !existA){
			if(s[i+1] == 'B'){
				existA = true;
				i++;
			}
		}
		else if(s[i] == 'B' && !existB && existA){
			if(s[i+1] == 'A'){
				existB = true;
				break;
			}
		}
	}
	
	if(existA && existB){
		cout << "YES" << endl;
	}
	else{
		existA = false;
		existB = false;
		
		for(int i = 0 ; i < s.size()-1 ; ++i){
			if(s[i] == 'B' && !existA){
				if(s[i+1] == 'A'){
					existA = true;
					i++;
				}
			}
			else if(s[i] == 'A' && !existB && existA){
				if(s[i+1] == 'B'){
					existB = true;
					break;
				}
			}
		}
		if(existA && existB){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	
	return 0;
}
