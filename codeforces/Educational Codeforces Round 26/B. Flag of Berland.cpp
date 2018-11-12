#include<bits/stdc++.h>

using namespace std;

char mat[102][102];
int n, m;

void checkHorizontal() {
	if(n % 3 != 0){
		puts("NO");
		return;
	}
	
	int tmp = n / 3;
	
	char R = mat[0][0];
	char G = mat[0 + tmp][0];
	char B = mat[0 + 2*tmp][0];
	
	
	for (int i = 0; i < tmp; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(mat[i][j] != R){
				puts("NO");
				return;
			}
		}
	}
	
	for (int i = tmp; i < 2*tmp ; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(mat[i][j] != G){
				puts("NO");
				return;
			}
		}
	}
	
	for (int i = 2*tmp; i < n ; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(mat[i][j] != B){
				puts("NO");
				return;
			}
		}
	}
	
	puts("YES");
}

void checkVertical() {
	if(m % 3 != 0){
		puts("NO");
		return;
	}
	
	int tmp = m / 3;
	
	char R = mat[0][0];
	char G = mat[0][0 + tmp];
	char B = mat[0][0 + 2*tmp];
	
	
	for (int i = 0; i < tmp; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(mat[j][i] != R){
				puts("NO");
				return;
			}
		}
	}
	
	for (int i = tmp; i < 2*tmp ; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(mat[j][i] != G){
				puts("NO");
				return;
			}
		}
	}
	
	for (int i = 2*tmp; i < m ; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(mat[j][i] != B){
				puts("NO");
				return;
			}
		}
	}
	
	puts("YES");
}

int main() {
	cin >> n >> m;
	
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}
	
	int r, g, b;
	
	r = g = b = 0;
	
	for (int i = 0; i < n; i++)
	{
		if(mat[i][0] == 'R')r++;
		else if(mat[i][0] == 'G')g++;
		else b++;
	}
	//cout << r << " " << g << " " << b << endl;
	if(r == n || g == n || b == n){
		//checkHorizontal();
		checkVertical();
		//cout << "test" << endl;
	}
	else {
		if(r != g || r != b || g != b)puts("NO");
		else {
			//checkVertical();
			checkHorizontal();
		}
	}
	
	return 0;
}
