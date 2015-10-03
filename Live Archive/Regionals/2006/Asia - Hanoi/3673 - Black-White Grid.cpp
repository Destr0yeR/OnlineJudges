#include<bits/stdc++.h>
#define mset(x, y) memset(x, y, sizeof(x))
#define MAX 1001

using namespace std;

char c[MAX][MAX];
int v[MAX];
int h[MAX];
int n;

int main(){
	int T;
	cin >> T;
	
	while(T--){
		cin >> n;
		mset(v, 0);
		mset(h, 0);
		for(int i = 1 ; i <= n ; ++i){
			for(int j = 1 ; j <= n ; ++j){
				cin >> c[i][j];
			}
		}
		
		for(int i = 1 ; i <= n ; ++i){
			for(int j = 1 ; j <= n ; ++j){
				if(c[i][j] == 'B'){
					v[i] = 1;
					h[j] = 1;
				}
			}
		}
		int _v = 0, _h = 0;
		for(int i = 1 ; i <= n ; ++i){
				_v += v[i];
				_h += h[i];
		}
		if(_v == n && _h == n)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	
	return 0;
}
