#include <bits/stdc++.h>

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d", &n, &m)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)

#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define forr(i, a, b) for(int i = a ; i < b ; ++i)

#define rforn(i, n) for(int i = n-1 ; i >= 0 ; --i)
#define rforr(i, a, b) for(int i = b-1 ; i >= a ; --i)

#define TEST(t) int T; cin >> T; for(int t = 1 ; t <= T ; ++t)

#define MAX 1000005

using namespace std;

int ka[MAX];

struct par{
	int n, k;
	par(){}
	par(int _i, int _k){n = _i; k = _k;}
	
	bool operator < (const par &b)const{
		return n < b.n;
	}
};

vector<par> vans;

void kmp_array(char* x, int len){
	ka[0] = 0;
	
	for(int i = 1, j = 0 ; i < len ; ){
		if(x[i] == x[j])ka[i++] = ++j;
		else{
			if(j == 0)ka[i++] = 0;
			else j = ka[j-1];
		}
	}
}

void solve(char* str, int len){
	vans.clear();
	kmp_array(str, len);
	
	for(int i = 1 ; i < len ; ++i){
		if(ka[i] && (i + 1)%(i + 1 - ka[i]) == 0){
			vans.push_back(par(i+1, (i + 1)/(i + 1 - ka[i])));
		}
	}
	
	sort(vans.begin(), vans.end());
	
	forn(i, (int)vans.size()){
		printf("%d %d\n", vans[i].n, vans[i].k);
	}
	
	puts("");
}

int main(){
	int len;
	char s[MAX];
	TEST(t){
		printf("Test case #%d\n", t);
		si(len);
		ss(s);
		solve(s, len);
	}
	
	return 0;
}

