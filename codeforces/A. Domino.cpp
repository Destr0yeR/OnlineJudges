#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int up = 0, low = 0;
    int ups[101], lows[101];
    for(int i = 0 ; i < n ; ++i){
        int a, b;
        cin>>ups[i]>>lows[i];
        up += ups[i];
        low += lows[i];
    }
    bool posible = false;
    if(up%2 == 0 && low%2 == 0){
        cout<<0<<endl;
    }
    else {
        for(int i = 0 ; i < n ; ++i){
            up -= ups[i];
            up += lows[i];

            low -= lows[i];
            low += ups[i];

            if(up%2 == 0 && low%2 ==0){
                posible = true;
                break;
            }
        }
        if(posible)cout<<1<<endl;
        else cout<<-1<<endl;
    }

    return 0;
}
