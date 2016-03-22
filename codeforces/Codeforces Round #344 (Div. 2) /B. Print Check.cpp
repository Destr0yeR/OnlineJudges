#include<bits/stdc++.h>

#define MAX 5001

using namespace std;

int r[MAX];
int rt[MAX];
int c[MAX];
int ct[MAX];

struct Input{
	int o, a, i;
	Input(){}
	Input(int _o, int _a, int _i){o = _o; a = _a; i = _i;}
};

stack<Input> s;

int main(){
	int n, m, k;
	int o, a, x;
	
	cin >> n >> m >> k;
	memset(r, 0, sizeof(r));
	memset(c, 0, sizeof(c));
	memset(rt, 0, sizeof(r));
	memset(ct, 0, sizeof(c));
	
	for(int i = 0 ; i < k ; ++i){
		cin >> o >> x >> a;
		s.push(Input(o, a, x));
	}
	Input tmp;
	int t = k + 1;
	while(!s.empty()){
		tmp = s.top();
		s.pop();
		o = tmp.o;
		a = tmp.a;
		x = tmp.i;
		
		if(o == 1){
			if(r[x] == 0){
				r[x] = a;
				rt[x] = t;
			}
		}
		else{
			if(c[x] == 0){
				c[x] = a;
				ct[x] = t;
			}
		}
		t--;
	}
	
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			if(j != 1)cout << " ";
			if(rt[i] >= ct[j]){
				cout << r[i];
			}
			else{
				cout << c[j];
			}
		}
		cout << "\n";
	}
	
	return 0;
}
