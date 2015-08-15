#include<bits/stdc++.h>
#define MAX 100001

using namespace std;

int x[MAX];
int y[MAX];

int main(){
	map<int, int> q;
	
	int n;
	
	cin >> n;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> x[i] >> y[i];
		q[x[i]]++;
	}
	
	for(int i = 0 ; i < n ; ++i){
		cout << ( n-1 + q[y[i]] ) << " " << ( n-1 - q[y[i]] ) << endl;
	}
	
	return 0;
}
