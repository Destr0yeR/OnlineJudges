#include<bits/stdc++.h>

using namespace std;

long long n, aux, x, y;

long long f[200001];
long long s[200001];

int main(){
	cin >> n;
	
	long long total_first = 0;
	long long total_second = 0;
	x = 0;
	y = 0;
	
	bool last_first = true;
	
	for(int i = 0 ; i < n ; ++i)
	{
		cin >> aux;
		if(aux>0){
			f[x++] = aux;
			total_first += aux;
			last_first = true;
		}
		else{
			s[y++] = -aux;
			total_second -= aux;
			last_first = false;
		}
	}
	
	if(total_first == total_second){
		
		bool first_winner;
		if(x > y){
			first_winner = true;
			for(int i =  0; i < y ; ++i){
				if(f[i] < s[i])first_winner = false;
				if(f[i]!=s[i])break;
			}
		}
		else if(y > x){
			first_winner = false;
			for(int i = 0 ; i < x ; ++i){
				if(f[i] > s[i])first_winner = true;
				if(f[i]!=s[i])break;
			}
		}
		else{
			bool equal = true;
			first_winner = false;
			for(int i = 0 ; i < x ;++i){
				if(f[i] > s[i])first_winner = true;
				if(f[i]!=s[i]){
					equal = false;
					break;
				}
			}
				
			if(equal){
				if(last_first)first_winner = true;
				else first_winner = false;
			}
		}
		
		if(first_winner)cout << "first" << endl;
		else cout << "second" << endl;
	}
	else if(total_first > total_second){
		cout << "first" << endl;
	}
	else{
		cout << "second" << endl;
	}
	
	return 0;
}
