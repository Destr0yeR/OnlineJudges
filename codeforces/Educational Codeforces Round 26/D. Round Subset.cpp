#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;

vector < pair<int, int > > v;
int n, k, x;

bitset<205> b;

int main() {
	
	cin >> n >> k;
	v.resize(n);
	
	int cnt2 = 0;
	int cnt5 = 0;
	
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		
		pair<int, int> p;
		p.X = p.Y = 0;
		
		while(x%2 == 0){
			p.X ++;
			x /= 2;
		}
		
		while(x%5 == 0){
			p.Y ++;
			y /= 5;
		}
		
		v[i] = p;
		cnt2 += pX;
		cnt5 += pY;
	}
	
	b.reset();
	while(k > 0){
		pair<int, int> p;
	}
	
	cout << min(cnt2, cnt5) << endl;
	
	return 0;
}
