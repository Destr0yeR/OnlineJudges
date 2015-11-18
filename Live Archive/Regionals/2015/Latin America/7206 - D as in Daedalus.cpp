#include<bits/stdc++.h>

using namespace std;

int dx[] = {10000, 1000, 100, 10, 1};

int main(){
	
	int n, m, tot, acu, p, x, a;
	
	while(cin>>m>>n){
		tot = 0;
		for(int i = 0 ; i < n ; ++i){
			cin >> p;
			cin >> x;
			acu = 0;
			for(int j = 1 ; j < m ; ++j){
				cin >> a;
				acu+=a;
			}
			
			if(acu < p){
				int j;
				for(j= 0 ; j < 5 ; j++){
					if(acu+dx[j] <= p)break;
				}
				
				if(acu + x <= p){
					tot+=(dx[j] - x);
				}
				else tot+=dx[j];
			}
		}
		cout << tot << endl;
	}
	
	return 0;
}
