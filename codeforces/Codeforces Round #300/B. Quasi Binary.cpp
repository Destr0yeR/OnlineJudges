#include<bits/stdc++.h>
#define mset(x, y) memset(x, y, sizeof(x));

using namespace std;

vector<int> v;

int sqt(int x){return x*x;}

int expo (int b, int e){
	if(e == 0)return 1;
	if(e == 1)return b;
	
	if(e%2 == 1){
		return sqt(expo(b, e/2))*b;
	}
	
	return sqt(expo(b, e/2));
}

void solve(int n){
	int aux = n, tmp, x = 0;
	int cont = 0;
	while(aux>0){
		tmp = aux%10;
		if(tmp)x += expo(10, cont);
		cont++;
		aux /= 10;
	}
	
	v.push_back(x);
	n-=x;
	if(n)solve(n);
}

int main(){
	int n;

	cin >> n;
	
	solve(n);
	
	cout << v.size() << endl;
	for(int i = 0 ; i < (int)v.size() ; ++i){
		if(i)cout << " ";
		cout << v[i];
	}
	cout << endl;
	
	return 0;
}
