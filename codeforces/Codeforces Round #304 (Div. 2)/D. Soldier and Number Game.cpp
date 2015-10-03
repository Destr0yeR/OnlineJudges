#include<bits/stdc++.h>
#define MAX 5000003

using namespace std;

int prim[MAX+1];

void sieve(){
    int aux;
    memset(prim,0,sizeof(prim));
    
    for(int i=2;i<=MAX;i++){
        if(prim[i]==0){
            for(int k=i;k<=MAX;k+=i){
                aux=k;
                while(aux%i==0){
                    prim[k]++;
                    aux/=i;
                }
            }
        }
    }
    for(int i=3;i<= MAX;i++){
        prim[i] += prim[i-1];
    }

}

int main(){
	int T, a, b;
	
	sieve();
	scanf("%d", &T);
	
	int ans;
	while(T--){
		scanf("%d %d", &a, &b);
		ans = (prim[a] - prim[b]);
		printf("%d\n", ans);
	}
	
	return 0;
}
