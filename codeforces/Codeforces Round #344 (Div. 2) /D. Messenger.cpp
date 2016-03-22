#include<bits/stdc++.h>

#define MAX 200001
#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)

using namespace std;

typedef long long ll;

struct block{
	ll l;
	char c;
	
	block(){}
	block(ll _l, int _c){l = _l; c = _c;}
	
	bool operator==(const block &b)const{
		return (c == b.c && l <= b.l);
	}
	
	bool operator<=(const block &b)const{
		return (c == b.c && l <= b.l);
	}
	
	ll operator-(const block &b){
		return l - b.l;
	}
};

block bt[MAX], bs[MAX];

vector<int> v[30];

int ka[MAX];

void read(block *b, int &x){
	int cnt = -1;
	char last = '2', c;
	ll l;
	
	for(int i = 0 ; i < x ; ++i){
		cin >> l >> c >> c;
		if(c != last)b[++cnt] = block(l, c);
		else b[cnt].l += l;
		last = c;
	}
	
	x = cnt + 1;
}

void kmp_array(block *b, int x){
	ka[1] = 0;
	x--;
	for(int i = 2, j = 1 ; i < x ; ){
		if(b[i] == b[j]){
			ka[i] = j;
			j++;
			i++;
		}
		else{
			if(j == 1){
				ka[i] = 0;
				i++;
			}
			else j = ka[j-1] + 1;
		}
	}
}

int main(){
	int n, m;
	sii(n, m);
	
	ll ans = 0LL;
	
	read(bt, n);
	read(bs, m);
	
	if(m  > 2){
		kmp_array(bs, m);
		
		for(int i = 1, j = 1 ; i < n-1 ; ){
			if(bt[i] == bs[j]){
				//cout << "1 : " << i << " " << j << endl;
				i++;
				j++;
				if(j == m-1){
					if(bs[0] <= bt[i-m+1] && bs[j] <= bt[i]){
						ans++;
					}
					if(j == 1){
						i++;
					}
					else j = ka[j-1] + 1;
				}
				
			}
			else {
				//cout << "2 : " << i << " " << j << endl;
				if(j == 1) i++;
				else j = ka[j-1] + 1;
			}
		}
	}
	else if(m == 2){
		for(int i = 0 ; i < n-1 ; ++i){
			if(bs[0] <= bt[i] && bs[1] <= bt[i+1])ans++;
		}
	}
	else if(m == 1){
		for(int i = 0 ; i < n ; ++i){
			if(bs[0] <= bt[i]){
				ans += bt[i] - bs[0] + 1LL;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
