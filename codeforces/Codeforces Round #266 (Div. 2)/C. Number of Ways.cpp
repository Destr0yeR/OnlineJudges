#include<bits/stdc++.h>
#define MAX 500001

using namespace std;
typedef long long ll;

int n, a[MAX];
ll sum, acu[MAX], s, s2;

int main(){
	
	cin >> n;
	sum = 0;
	
	for(int i = 0 ; i < n ; ++i){
		cin>>a[i];
		sum += a[i];
	}
	
	ll ts1 = 0, ts2 = 0;
	
	if(sum%3){
		cout << "0" << endl;
	}
	else{
		s = sum/3;
		s2 = 0;
		if (s==0) {
			for (int i=0;i<n-1;i++) {
				s2+=a[i];
				if (s2==0) ts1++;
			}
			cout << ts1*(ts1-1)/2 << endl;
		}
		else{
			for (long long i=0;i<n-1;i++) {
				s2 += a[i];
				if (s2==s) ++ts1;
				else if (s2==2*s) ts2+=ts1;
			}
			cout << ts2 << endl;
		}
	}
	
	return 0;
}
