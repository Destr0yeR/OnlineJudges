#include<bits/stdc++.h>

#define mset(x,y) memset(x, y, sizeof(x))

using namespace std;

struct par{
	string x, y;
};

int main(){
	int aux, contx, conty, t, maxi, m, n;
	string x, y, ansx, ansy, c;
	
	map<char, char> s, r;
	par p[101];
	cin >> t;
	
	for(int i = 0 ; i < t ; ++i){
		cin >> p[i].x >> p[i].y;
	}
	maxi = 0;
	for(int i =  0 ; i < t ; ++i){
		cin >> n >> m;
		x = p[i].x;
		y = p[i].y;
		contx = 0;
		conty = 0;
		for(int j = 0 ; j < n ; ++j){
			for(int k = 0 ; k < m ; ++k){
				cin >> c;
				if(x == c){
					contx++;
				}
				else if(y == c){
					conty++;
				}
			}
		}
		if(x == y){
			conty = contx/2;
			contx /= 2;
		}
		aux = min(contx, conty);
		if(maxi < aux){
			ansx = x;
			ansy = y;
			maxi = aux;
		}
	}
	
	cout << ansx << " " << ansy << endl;
	
	return 0;
}
