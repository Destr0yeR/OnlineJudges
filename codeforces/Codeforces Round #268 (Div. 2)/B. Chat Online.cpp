#include<bits/stdc++.h>

using namespace std;

struct segment{
	int l, r;
};

int main(){
	
	int p, q, l, r;
	
	cin >> p >> q >> l >> r;
	
	segment z[51], x[51];
	
	for(int i = 0 ; i < p ; ++i)cin >> z[i].l >> z[i].r;
	for(int i = 0 ; i < q ; ++i)cin >> x[i].l >> x[i].r;
	
	bool posible;
	int cont = 0;
	
	for(int i = l ; i <= r ; ++i){
		posible = false;
		
		for(int j = 0; j < p ; ++j){
			for(int k = 0 ; k < q ; ++k){
				if(z[j].l <= x[k].r + i && z[j].r >= x[k].l + i)posible = true;
			}
		}
		
		if(posible)++cont;
	}
	
	cout << cont << endl;

	return 0;
}
