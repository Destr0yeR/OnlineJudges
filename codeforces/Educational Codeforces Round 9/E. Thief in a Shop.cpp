#include<bits/stdc++.h>

#define MAX 1000005
#define NMAX 1001

using namespace std;

bitset<MAX> v;
vector<int> ans;
int p[NMAX];

map< pair<int, int> , int > m;

void init(){
	m.clear();
	v.reset();
	ans.clear();
}

int solve(int sum, int k, int n){
	if(k == 0){
		if(v[sum] == 0){
			v[sum] = 1;
			ans.push_back(sum);
		}
		return sum;
	}
	pair<int, int> q = make_pair(sum, k);
	if(m.count(q) > 0){
		return m[q];
	}
	
	int tmp = 0;
	
	for(int i = 0 ; i < n ; ++i){
		tmp += solve(sum + p[i], k-1, n);
	}
	
	return m[q] = tmp;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	
	for(int i = 0 ; i < n ; ++i)cin >> p[i];
	
	init();
	solve(0, k, n);
	
	sort(ans.begin(), ans.end());
	
	int sz = ans.size();
	
	printf("%d", ans[0]);
	for(int i = 1 ; i < sz ; ++i){
		printf(" %d", ans[i]);
	}
	puts("");
	
	return 0;
}
