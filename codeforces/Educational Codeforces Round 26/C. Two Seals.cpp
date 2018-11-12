#include<bits/stdc++.h>

using namespace std;

vector< pair<int, int > > v;
int n, a, b;

#define X first
#define Y second

bool fit(int i, int j){
	pair<int, int> p, q;
	
	p = v[i];
	q = v[j];
	
	if(p.X + q.X <= a && q.Y <= b && p.Y <= b)return true;
	if(p.Y + q.Y <= a && q.X <= b && p.X <= b)return true;
	if(p.Y + q.X <= a && q.Y <= b && p.X <= b)return true;
	if(p.X + q.Y <= a && q.X <= b && p.Y <= b)return true;
	
	if(p.X + q.X <= b && q.Y <= a && p.Y <= a)return true;
	if(p.Y + q.Y <= b && q.X <= a && p.X <= a)return true;
	if(p.Y + q.X <= b && q.Y <= a && p.X <= a)return true;
	if(p.X + q.Y <= b && q.X <= a && p.Y <= a)return true;
	
	return false;
}

int main() {
	int x, y;
	cin >> n >> a >> b;
	
	if(a > b)swap(a, b);
	
	int ans = 0;
	
	v.resize(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		
		v[i] = make_pair(x, y);
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if(fit(i, j)){
				ans = max(ans, v[i].first * v[i].second + v[j].first * v[j].second);
			}
		}
		
	}
	
	cout << ans << endl;
	
	
	return 0;
}
