#include<bits/stdc++.h>

//2147483647
//#define MAX 2147483647
#define MAX 21474836

using namespace std;

bitset<MAX> b;
vector<int> p;

void sieve(){
	b.set();
	
	int sq = sqrt(MAX);
	
	for(int j=2;j*2<MAX;j++){
		b[2*j] = 0;
	}
	
	for(int i = 3 ; i <= sq ; i+=2){
		if(b[i]){
			for(int j=i;j*i<MAX;j++){
				b[i*j] = 0;
			}
		}
	}
	p.push_back(2);
	for(int i = 3 ; i < MAX ; i+=2){
		if(b[i]){
			p.push_back(i);
		}
	}
	
}

int main(){
	sieve();
	cout << "a" << endl;
	return 0;
}
