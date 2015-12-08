#include<bits/stdc++.h>

#define MAX 1000001

using namespace std;

bitset<MAX> b;

void sieve(){
	int sq = sqrt(MAX);
	b.set();
	
	b[0] = b[1] = 0;

	for(int i = 4 ; i < MAX ; i+=2)b[i] = 0;
	
	for(int i = 3 ; i <= sq ; i+=2)if(b[i] == 1)for(int j = i ; j*i < MAX ; j+=2)b[i*j] = 0;
}

int reverse(int n){
	int tmp = 0;
	
	while(n){
		tmp *= 10;
		tmp += (n%10);
		n /= 10;
	}
	
	return tmp;
}

int main(){
	sieve();
	int n, r;
	
	while(scanf("%d", &n) == 1){
		if(b[n] == 1){
			r = reverse(n);
			if(b[reverse(n)] == 1 && r != n)printf("%d is emirp.\n", n);
			else printf("%d is prime.\n", n);
		}
		else printf("%d is not prime.\n", n);
	}
	
	return 0;
}
