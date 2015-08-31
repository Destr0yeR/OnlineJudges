#include<bits/stdc++.h>
#define MAX 100005

using namespace std;

int v[MAX];

int c[MAX];

int n, x, y, total, ans, siz;

bool cmp(int a, int b){
	return a < b;
}

bool cmp2(int a, int b){
	return a > b;
}


int main(){
	cin >> n;
	total = 0;
	siz = 0;
	memset(c, 0, sizeof(c));
	for(int i = 0 ; i < n ; ++i){
		cin >> x >> y;
		if(x){
			c[x]++;
			v[siz++] = y;
		}
		else{
			total++;
		}
	}
	ans = 0;
	sort(v, v+siz, cmp);
	sort(c, c+MAX, cmp2);

	for(int i = 0 ; total <= c[0]/2 ; ++i){
		ans += v[i];
		total++;
	}
	
	cout << ans << endl;
	
	
	return 0;
}
