#include <bits/stdc++.h>

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)

#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define forr(i, a, b) for(int i = a ; i < b ; ++i)

#define rforn(i, n) for(int i = n-1 ; i >= 0 ; --i)
#define rforr(i, a, b) for(int i = b-1 ; i >= a ; --i)

#define mset(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()

#define TEST(t) int T; cin >> T; for(int t = 1 ; t <= T ; ++t)

#define MAX 2000005

using namespace std;

char a[MAX], b[MAX], ra[MAX], rb[MAX], ca[MAX], cb[MAX];

int kra[MAX], krb[MAX];

void kmp_array(char* x, int* k_arr, int len){
	k_arr[0] = 0;
	
	for(int i = 1, j = 0; i < len ; ){
		if(x[i] == x[j])k_arr[i++] = ++j;
		else{
			if(j)j = k_arr[j-1];
			else k_arr[i++] = 0;
		}
	}
}

int main(){
	char sep[] = "\n";
	
	cin.getline(a, MAX);
	cin.getline(b, MAX);
	
	int len = strlen(a);
	
	if(len != (int)strlen(b)){
		puts("-1 -1");
		return 0;
	}
	
	strcpy(cb, b);
	strcpy(rb, b);
	reverse(rb, rb + len);
	
	strcat(cb, sep);
	strcat(cb, a);
	cb[len+1] = '\n';
	
	kmp_array(cb, kra, 2*len + 1);
	
	int diff_max = 0, aux_max;
	
	for(int i = len + 1 ; i < 2*len ; ++i){
		if(kra[i] > diff_max){
			diff_max = kra[i];
			aux_max = i - len - diff_max;
		}
	}
	
	strcat(rb, sep);
	
	strcat(rb, a);
	
	
	kmp_array(rb, krb, 2*len + 1);
	
	int i_max = 0;
	diff_max++;
	
	for(int i = len + 1 ; i < 2*len ; ++i){
		i_max = max(krb[i], i_max);
	}
	
	i_max --;
	
	cout << i_max << " " << aux_max << " "  << diff_max << endl;
	
	int j = i_max + diff_max;
	
	while(j >= len)j--;
	
	while(i_max >= aux_max){
		i_max--;
		j--;
	}
	
	if(j <= i_max){
		puts("-1 -1");
		return 0;
	}
	
	if(i_max < 0){
		puts("-1 -1");
		return 0;
	}
	cout  << i_max << " " << j << endl;
	
	return 0;
}



