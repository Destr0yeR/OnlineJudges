#include<bits/stdc++.h>

using namespace std;

int main()
{
    int h[31];
    int g[31];
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; ++i) cin>>h[i]>>g[i];
    int total = 0;

    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            if(h[i] == g[j])total++;
        }
    }

    cout<<total<<endl;

    return 0;
}
