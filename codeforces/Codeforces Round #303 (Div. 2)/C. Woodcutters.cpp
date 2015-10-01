#include<bits/stdc++.h>
#define MAX_N 100002

#define MAX 2000000005

typedef long long ll;

ll x[MAX_N], h[MAX_N], last;
int n, cont;

using namespace std;

int main(){
	
	cin >> n;
	
	x[0] = -MAX;
	h[0] = 0;
	for(int i = 1 ; i <= n ; ++i)cin >> x[i] >> h[i];
	x[n+1] = MAX;
	h[0] = 0;
	
	last = x[0] + h[0];
	cont = 0;
	for(int i = 1 ; i <= n ; ++i){
		if(last < x[i] - h[i]){
			last = x[i];
			cont++;
		}
		else if(x[i+1] > x[i] + h[i]){
			last = x[i] + h[i];
			cont++;
		}
		else last = x[i];
	}
	
	cout << cont << endl;
	
	return 0;
}
