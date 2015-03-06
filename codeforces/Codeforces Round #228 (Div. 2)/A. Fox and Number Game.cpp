#include<bits/stdc++.h>

using namespace std;

int mcd(int a, int b){
    if(b == 0)return a;
    return mcd(b,a%b);
}

int main()
{
    int n;
    cin>>n;
    int v[101];

    for(int i = 0 ; i < n ; ++i)cin>>v[i];

    int _mcd = v[0];

    for(int i = 1 ; i < n ; ++i){
        _mcd = mcd(_mcd, v[i]);
    }

    cout<<n*_mcd<<endl;

    return 0;
}
