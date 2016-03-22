#include <bits/stdc++.h>

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)

#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define forr(i, a, b) for(int i = a ; i < b ; ++i)

#define rforn(i, n) for(int i = n-1 ; i >= 0 ; --i)
#define rforr(i, a, b) for(int i = b-1 ; i >= a ; --i)

#define TEST(t) int T; cin >> T; for(int t = 1 ; t <= T ; ++t)

#define MAX 200005

using namespace std;

int ka[MAX];

void kmp_array(char* x, int len){
	ka[0] = 0;
	
	for(int i = 1, j = 0 ; i < len ; ){
		if(x[i] == x[j])ka[i++] = ++j;
		else{
			if(j)j = ka[j-1];
			else ka[i++] = 0;
		}
	}
}

int main(){
	char s[MAX], rs[MAX];
	int rlen, slen;
	
	while(ss(s) == 1){
		strcpy(rs, s);
		slen = strlen(s);
		reverse(rs, rs + slen);
		strcat(rs, s);
		rlen = strlen(rs);
		
		kmp_array(rs, rlen);
		
		printf("%s", s);
		for(int i = ka[rlen - 1] ; i < slen ; ++i){
			printf("%c", rs[i]);
		}
		puts("");
	}

	return 0;
}

