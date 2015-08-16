#include<bits/stdc++.h>
#define MAX 1000001

using namespace std;

int n, m, aux;
vector<int> A;
vector<int> B;

int main(){
	cin >> n >> m;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> aux;
		A.push_back(aux);
	}
	
	for(int i = 0 ; i < m ; ++i){
		cin >> aux;
		B.push_back(aux);
	}
	
	int falta = n;
	int j = 0;
	
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	
	for(int i = 0 ; i < n; ++i){
		while(A[i] > B[j] && j < m){
			j++;
		}
		if(j > m)break;
		if(A[i] <= B[j]){
			falta--;
		}
	}
	
	cout << falta << endl;
	
	return 0;
}
