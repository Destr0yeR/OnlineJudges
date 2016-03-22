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
#define MAXS 1000001

using namespace std;

int ka[MAXS];
vector<int> v;

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

void kmp(char* text, char *path, int plen){
	int tlen = strlen(text);
	
	if(tlen < plen){
		return;
	}
	
	kmp_array(path, plen);
	v.clear();
	for(int i = 0, j = 0 ; i < tlen ; ){
		if(text[i] == path[j]){
			i++;
			j++;
		}
		else{
			if(j == 0)i++;
			else j = ka[j - 1];
		}
		if(j == plen){
			v.push_back(i - plen);
			j = ka[j - 1];
		}
	}
	
	if(v.size() != 0){
		forn(i, (int)v.size()){
			printf("%d\n", v[i]);
		}
	}
}

int main(){
	char s[MAX], qs[MAXS];
	int plen;
	int tc = 0;
	while(si(plen) == 1){
		if(tc++)printf("\n");
		ss(qs);
		ss(s);
		kmp(s, qs, plen);
	}

	return 0;
}

