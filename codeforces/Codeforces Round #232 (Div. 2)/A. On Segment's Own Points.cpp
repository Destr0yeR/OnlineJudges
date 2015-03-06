#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, l, r;
    int a, b;
    cin>>n;
    cin>>a>>b;
    int v[101];
    for(int i = 0 ; i <= 100 ; ++i)v[i] = 0;

    for(int i = a+1 ; i <= b ; ++i)v[i] = 1;

    for(int i = 1 ; i < n ; ++i){
        cin>>l>>r;
        for(int j = l+1 ; j <= r ; ++j)v[j] = 0;
    }
    int total = 0;
    for(int i = 0 ; i <= 100 ; ++i){
        if(v[i] == 1)total++;
    }

    cout<<total<<endl;
    return 0;
}
