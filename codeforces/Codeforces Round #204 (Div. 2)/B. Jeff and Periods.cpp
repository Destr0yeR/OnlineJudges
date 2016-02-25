#include<bits/stdc++.h>

#define MAX 100005

using namespace std;


int c[MAX], p[MAX], l[MAX], pos[MAX];

int main(){
	
	int n, x, aux;
	set<int> s;
	
	scanf("%d", &n);
	
	for(int i = 0 ; i < MAX ; ++i){
		c[i] = 0;
		p[i] = l[i] = -1;
		pos[i] = 1;
	}
	
	for(int i = 0 ; i < n ; ++i){
		scanf("%d", &x);
		
		s.insert(x);
		
		if(c[x] == 0){
			p[x] = 0;
		}
		else{
			aux = i - l[x];
			if(c[x] == 1){
				p[x] = aux;
			}
			else{
				if(aux != p[x])pos[x] = 0;
			}
		}
		
		l[x] = i;
		c[x] ++;
	}
	
	set<int>::iterator it;
	int cont = 0;
	
	for(it = s.begin() ; it != s.end() ; ++it){
		if(pos[*it] == 1)cont++;
	}
	
	
	cout << cont << endl;
	
	for(it = s.begin() ; it != s.end() ; ++it){
		if(pos[*it] == 1){
			cout << *it << " " << p[*it] << endl;
		}
	}
	
	return 0;
}
