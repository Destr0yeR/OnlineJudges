#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n, m;
    string S;
    cin>>n>>m;
	for (int i = 0; i < n; i++) {
		cin>>S;
		for (int j = 0; j < m; j++)
			if (S[j] == '.') {
				if ((i + j) & 1)	S[j] = 'W';
				else	S[j] = 'B';
			}
		cout<<S<<endl;
	}
    return 0;
}

