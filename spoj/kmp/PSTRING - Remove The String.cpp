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
 
#define MAXS 1001
#define MAX 10001
 
using namespace std;
 
int ka[MAXS];
 
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
 
void kmp(char* text, char* path){
	int plen = strlen(path);
	int tlen = strlen(text);
	kmp_array(path, plen);
	int cnt = 0;
 
	if(plen - 1 == ka[plen-1]){	
		for(int i = 0, j = 0 ; i < tlen ; ){
			if(text[i] == path[j]){
				i++;
				j++;
			}
			else{
				if(j)j = ka[j-1];
				else i++;
			}
			if(j == plen){
				cnt++;
				j = ka[j-1];
			}
		}
	}
	else{
		for(int i = 0, j = 0 ; i < tlen ; ){
			if(text[i] == path[j]){
				i++;
				j++;
			}
			else{
				if(j)j = ka[j-1];
				else i++;
			}
			if(j == plen){
				cnt++;
				j--;
			}
		}
	}
 
	printf("%d\n", cnt);
}
 
int main(){
	char text[MAX], path[MAXS];
 
	ss(text);
	ss(path);
	kmp(text, path);
 
	return 0;
}
