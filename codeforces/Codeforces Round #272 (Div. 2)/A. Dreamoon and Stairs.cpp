#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;

    int k = n/2;
    int r = n%2;

    while((k+r)%m != 0){
        k--;
        r += 2;
        if(k<0 || r<0)break;
    }
    if(k<0 || r<0)cout<<-1<<endl;
    else cout<<(k+r)<<endl;

    return 0;
}
