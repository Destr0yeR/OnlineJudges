#include<bits/stdc++.h>
#define MAX 1000001

int toNum(char c){return c-'0';}

int a[MAX], b[MAX];

using namespace std;

int main()
{
    int k, aux;
    long long ans = 0;
    string s;
    
    cin >> k;
    cin >> s;
    
    int sz = s.size();
    
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    
    for(int i = 0 ; i < sz ; ++i)a[i+1] = a[i] + (toNum(s[i]));
    
    b[0] = 1;
    
    for(int i = 0 ; i < sz ; ++i){
		aux = a[i+1]-k;
		if(aux>=0)ans+=b[aux];
		b[a[i+1]]++;
	}
    
	cout << ans << endl;

    return 0;
}
