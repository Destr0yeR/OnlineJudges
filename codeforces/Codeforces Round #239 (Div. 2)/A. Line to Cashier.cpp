#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, tmp, a;
    int k[101];

    cin>>n;

    for(int i = 0 ; i < n ; ++i)cin>>k[i];

    int minimo = 99999999;
    int cont_min;

    for(int i = 0 ; i < n ; ++i){
        tmp = 0;
        for(int j = 0 ; j < k[i] ; ++j){
            cin>>a;
            tmp += a;
        }
        if((tmp*5 + k[i]*15)<(minimo*5+cont_min*15))minimo=tmp,cont_min=k[i];
    }

    cout<<(minimo*5 + cont_min*15)<<endl;

    return 0;
}
