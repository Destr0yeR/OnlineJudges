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

#define MAX 2000005

int ka[MAX];

using namespace std;

void kmp_array(char *x, int len){
	ka[0] = 0;
	
	for(int i = 1, j = 0 ; i < len ; ){
		if(x[i] == x[j]){
			j++;
			ka[i] = j;
			i++;
		}
		else{
			if(j == 0){
				ka[i] = 0;
				i++;
			}
			else j = ka[j-1];
		}
	}
}

int main(){
	char s[MAX], rs[MAX];
	int slen, rlen;
	while(ss(s) == 1){
		strcpy(rs, s);
		reverse(rs, rs + strlen(rs));
		strcat(rs, s);
		rlen = strlen(rs);
		slen = strlen(s);
		kmp_array(rs, rlen);
		
		printf("%s", s);
		forr(i, ka[rlen-1], slen){
			printf("%c", rs[i]);
		}
		
		printf("\n");
	}
	
	return 0;
}

