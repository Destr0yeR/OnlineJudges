#include<bits/stdc++.h>

using namespace std;

int luckyDigits(int x){
    int mod;
    int total = 0;
    while(x>0){
        mod = x%10;
        if(mod == 4 || mod == 7)total++;
        x /= 10;
    }
    return total;
}

int main()
{
    int n, k, a, total=0;
    cin>>n>>k;

    for(int i = 0 ; i < n ; ++i){
        cin>>a;
        if(luckyDigits(a)<=k)total++;
    }
    cout<<total<<endl;
    return 0;
}
