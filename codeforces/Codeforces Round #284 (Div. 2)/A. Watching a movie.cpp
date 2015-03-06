#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin>>n>>x;
    int l, r;
    int total = 0;
    int ini = 1;
    for(int i = 1 ; i <= n ; ++i){
        cin>>l>>r;
        int mod = (l-ini)%x;
        total += (r-l+1)+mod;
        ini = r+1;
    }

    cout<<total<<endl;

    return 0;
}
