#include<iostream>
#define MAX 50001

using namespace std;

int w, n, i, j, k, total, cont, maxi;

int x[MAX];

int main(){
	
	while(cin >> w >> n){
		if(w == 0 && n == 0)break;
		for(i = 0 ; i < n ; ++i)cin >> x[i];
		total = 0;
		cont = 0;
		maxi = 0;
		for(i = 0 ; i < n ; ++i){
			total += x[i];
			cont++;
			if(total + cont - 1 > w){
				cont--;
				total-=x[i];
				if(cont > 1){
					maxi = max(maxi, (w-total + cont-2)/(cont-1));
				}
				else{
					maxi = max(maxi, w-total);
				}
				total = 0;
				cont = 0;
				n -= cont;
				i--;
			}
			else if(total + cont - 1 == w){
				maxi = max(maxi, cont-1);
				n -= cont;
				total = 0;
				cont = 0;
			}
			else if(cont == n && n != 1){
				maxi = max(maxi, (w - total + cont - 2)/(cont-1));
			}
		}
		
		cout << maxi << endl;
	}
	
	return 0;
}

/** 
11 4
4 2 1 3
5 7
1 1 1 2 2 1 2
11 7
3 1 3 1 3 3 4
23
100 3
30 30 39
30 3
2 5 3
0 0
* */
