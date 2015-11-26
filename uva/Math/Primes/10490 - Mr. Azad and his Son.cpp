#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ex[32];
bitset<32> b;

void sieve(){
	
}

int isPrime(int n){
	int sq = sqrt(n);
	
	if(n <= 1)return 0;
	if(n == 2)return 1;
	if(n %2 == 0)return 0;
	
	for(int i = 3 ; i <= sq ; i+=2){
		if(n%i == 0)return 0;
	}
	return 1;
}

void getExpo(){
	ll e = 1;
	
	for(int i = 0 ; i < 32 ; ++i){
		ex[i] = e;
		e*=2;
		b[i] = isPrime(ex[i] - 1);
	}
}


int main(){
	sieve();
	getExpo();
	
	int n;
	
	while(scanf("%d", &n) == 1){
		if(n == 0)break;
		if(n == 1){
			cout << "Perfect: "<< 1 << "!\n";
		}
		else if(b[n] == 1){
			cout << "Perfect: "<< ex[n-1]*(ex[n]-1) << "!\n";
		}
		else if(isPrime(n)){
			printf("Given number is prime. But, NO perfect number is available.\n");
		}
		else{
			printf("Given number is NOT prime! NO perfect number is available.\n");
		}
	}
	
	return 0;
}
