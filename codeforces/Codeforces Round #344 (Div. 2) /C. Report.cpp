#include<bits/stdc++.h>

#define MAX 200001

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)

using namespace std;

int a[MAX], ans[MAX];

struct Query{
	int t, r;
	Query(){}
	Query(int _t, int _r){t = _t; r = _r;}
};

Query q[MAX];

int _r, _l;

int main(){
	int n, m, t, r, l;
	sii(n, m);
	for(int i = 0 ; i < n ; ++i)si(a[i]);
	
	int last = INT_MAX, cnt = 0;
	
	for(int i = 0 ; i < m ; ++i){
		cin >> t >> r;
		while(r >= last && cnt > 0){
			cnt--;
			last = q[cnt-1].r;
		}
		q[cnt] = Query(t, r);
		last = r;
		cnt++;
	}
	q[cnt++] = Query(1, 0);
	
	for(int i = 0 ; i < n ; ++i)ans[i] = a[i];
	
	sort(a, a + q[0].r);
	
	int _l = 0;
	int _r = q[0].r - 1;
	
	for(int i = 1 ; i < cnt ; ++i){
		t = q[i-1].t;
		r = q[i-1].r;
		l = q[i].r;
		
		if(t == 1){
			for(int j = r-1 ; j >= l; --j){
				ans[j] = a[_r--]; 
			}
		}
		else{
			for(int j = r-1 ; j >= l; --j){
				ans[j] = a[_l++]; 
			}
		}
	}
	
	for(int i = 0 ; i < n ; ++i){
		if(i)cout << " ";
		cout << ans[i];
	}
	cout << "\n";
	
	return 0;
}
