#include<bits/stdc++.h>

using namespace std;

int main(){
	int T, n, a[101];
	
	scanf("%d", &T);
	
	for (int i = 1; i <= T; ++i)
	{
		cin >> n;
		for (int j = 0; j < n; ++j)
		{
			cin >> a[j];
		}
		
		sort(a, a + n);
		
		printf("Case %d: %d\n", i, a[(n-1)/2]);
	}
	
	
	return 0;
}
