#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m , v = 999999999, c = 999999999, tmp, p = 0;
    cin>>n>>m;
    while(n--){
        cin>>tmp;
        if(tmp<v)v=tmp;
        if(tmp>p)p=tmp;
    }
    while(m--){
        cin>>tmp;
        if(tmp<c)c=tmp;
    }

    if(max(2*v,p)<c)cout<<max(2*v,p);
    else cout<<-1;

    cout<<endl;

    return 0;
}
