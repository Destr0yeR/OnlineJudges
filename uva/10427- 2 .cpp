#include <bits/stdc++.h>

using namespace std;

int sq (int x ) {
	return x*x;
}

int fast_expo(int base, int expo) {
	if(expo == 0) return 1;
	if(expo == 1) return base;
	
	if(expo % 2 == 1) {
		return sq(fast_expo(base, expo/2)) * base;
	}
	
	return sq(fast_expo(base, expo/2));
}

void findNthDigit(int N) {
	if(N < 10) {
		cout << N << endl;
		return;
	}

	int x = 0;
	int offset = 0;
	int base = 1;
	int nextOffset = 9;
	
	for(x = 0 ; offset + nextOffset < N ;  ++x) {
		offset += nextOffset;
		base *= 10;
		nextOffset = 9 * base * (x+2);
	}
	
	int p = N - offset - 1;
	int mod = p % (x+1);
	
	int num = base + p / (x+1);
	string strNum = to_string(num);
	
	cout <<  strNum[mod] << endl;
}

int main() {
	int n;
	while(cin >> n){
		findNthDigit(n);
	}
	
	return 0;
}
