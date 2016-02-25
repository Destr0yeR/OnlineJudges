#include<bits/stdc++.h>

const double pi = 4*atan(1);

using namespace std;

double sq(double x){return x*x;}

int main(){
	double ans = 0.0;
	double a[101];
	int n;
	
	cin >> n;
	
	for(int i = 0 ; i < n ; ++i)cin >> a[i];
	
	sort(a, a + n);
	
	for(int i = n-1 ; i >= 0 ; i-=2)ans+=sq(a[i]);
	for(int i = n-2 ; i >= 0 ; i-=2)ans-=sq(a[i]);
	
	ans *= pi;
	
	printf("%.10f", ans);
	
	return 0;
}
