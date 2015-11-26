#include<bits/stdc++.h>

#define MAX 1000001

using namespace std;

int v[MAX];

int main(){
	
	int n, acu = 0, maxi = 0, id;
	
	char c;
	
	cin >> n;
	
	while(n--){
		cin >> c >> id;
		
		if(c == '+'){
			v[id] = 1;
			acu++;
		}
		else{
			if(v[id] == 1){
				acu--;
			}
			else{
				maxi++;
			}
		}
		maxi = max(maxi, acu);
	}
	
	cout << maxi << endl;
	
	return 0;
}
