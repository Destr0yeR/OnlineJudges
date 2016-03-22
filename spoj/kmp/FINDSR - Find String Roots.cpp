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

#define MAX 100001

using namespace std;

int ka[MAX];

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

int solve(char *s){
	int len = strlen(s);
	kmp_array(s, len);
	
	int ans = 1;
	int posi = len - 1;
	int x, ante;
	
	x = posi - ka[posi-1];
	
	while(posi != 0){
		ante = posi;
		posi = ka[posi-1];
		if(s[ante] == s[posi] && x == ante - posi){
			ans++;
		}
	}	
	
	if(ans > 1){
		if(x*ans != len)ans = 1;
	}
	
	return ans?ans:1;
}

int main(){
	char s[MAX];
	
	while(ss(s)){
		if(s[0] == '*')return 0;
		printf("%d\n", solve(s));
	}
	

	return 0;
}

