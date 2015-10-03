#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;

int dig[10];

int num[MAX];

int main(){
	
	int n, d = MAX, len, aux;
	cin >> n;
	for(int i = 1 ; i < 10 ; ++i){
		cin>>dig[i];
		d = min(d, dig[i]);
	}
	
	len = n/d;
	aux = len-1;
	
	char s[len+1];
	s[len] = '\0';
	
	int pos = 0;
	if(len == 0)cout << -1 << endl;
	else{
		for(int i = 0 ; i < len ; ++i){
			int j;
			for(j = 9 ; j >= 1 ; --j){
				if(dig[j] + aux*d <= n)break;
			}
			n-=dig[j];
			aux--;
			s[pos++] = (j+'0');
		}
	}
	cout << s << endl;
	
	return 0;
}
