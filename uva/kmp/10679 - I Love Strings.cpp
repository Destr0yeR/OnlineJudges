#include <bits/stdc++.h>

#define MAX 100001
#define MAXS 1001

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d", &n, &m)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)

#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define forr(i, a, b) for(int i = a ; i < b ; ++i)

#define rforn(i, n) for(int i = n-1 ; i >= 0 ; --i)
#define rforr(i, a, b) for(int i = b-1 ; i >= a ; --i)

#define TEST(t) int T; cin >> T; for(int t = 1 ; t <= T ; ++t)

using namespace std;

int ka[MAXS];

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
			else j = ka[j - 1];
		}
	}
	/*printf("\n --- KMP ARRAY --- \n");
	for(int i = 0 ; i < len ; ++i){
		printf(" %d", ka[i]);
	}
	printf("\n");*/
}

void kmp(char* text, char* path){
	kmp_array(path, strlen(path));
	
	int tlen = strlen(text), plen = strlen(path);
	
	for(int i = 0, j = 0 ; i < tlen ; ){
		//cout << i << " " << j << endl;
		if(text[i] == path[j]){
			i++;
			j++;
		}
		else{
			if(j == 0)i++;
			else j = ka[j - 1];
		}
		if(j == plen){
			printf("y\n");
			return;
		}
	}
	
	printf("n\n");
}

int main(){
	char s[MAX], qs[MAXS];
	int q;
	
	TEST(t){
		ss(s);
		si(q);
		
		forn(i, q){
			ss(qs);
			kmp(s, qs);
		}
	}

	return 0;
}
