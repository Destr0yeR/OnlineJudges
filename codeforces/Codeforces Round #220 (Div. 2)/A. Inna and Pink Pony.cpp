#include<bits/stdc++.h>
#include <stdio.h>

#define INF 2147483647
using namespace std;

int n, m, i, j, a, b;

int solve(int i, int j){
	int ret = 0;
	if (i % a  || j % b) return INF;
	ret = min(i/a, j/b);
	i -= ret * a;
	j -= ret * b;
	if (i && j) return INF;
	if (j/b % 2 != 0 || i/a % 2 != 0) return INF;
	if (i == 0 && j != 0 && a >= n) return INF;
	if (j == 0 && i != 0 && b >= m) return INF;
	return ret + j/b + i/a;
}

int main(void){
	cin>>n>>m>>i>>j>>a>>b;
	int x = min(min(solve(i-1,j-1),solve(n-i,j-1)),min(solve(i-1,m-j),solve(n-i,m-j)));
	if (x < INF)cout<<x<<endl;
	else cout<<"Poor Inna and pony!"<<endl;
	return 0;
}
