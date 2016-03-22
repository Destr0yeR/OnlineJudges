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

#define MAX 1000001

using namespace std;

int ka[MAX];

void kmp_array(char *x, int len){
	ka[0] = 0;
	
	for(int i = 1, j = 0 ; i < len ; ){
		if(x[i] == x[j])ka[i++] = ++j;
		else{
			if(j == 0)ka[i++] = 0;
			else j = ka[j-1];
		}
	}
}

int solve(char *str){
	int len = strlen(str);
	kmp_array(str, len);
	
	int ans = 1, ante = 1, posi = len - 1, per = posi - ka[posi-1];
	
	while(posi !=0){
		ante = posi;
		posi = ka[posi-1];
		if(str[ante] == str[posi] && per == ante - posi)ans++;
	}
	
	if(ans > 1){
		if(ans * per != len)ans = 1;
	}
	
	return ans;
}

int main(){
	char s[MAX];
	
	while(ss(s)){
		if(s[0] == '.')return 0;
		printf("%d\n", solve(s));
	}
	
	return 0;
}

