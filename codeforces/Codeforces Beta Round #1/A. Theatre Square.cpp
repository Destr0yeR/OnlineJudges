#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ull n, m, a, rpta;
    cin>>n>>m>>a;

    rpta = ((n+a-1)/a)*((m+a-1)/a);

    cout<<rpta<<endl;
    return 0;
}
