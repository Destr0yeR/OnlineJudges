#include<bits/stdc++.h>

using namespace std;

int main()
{
    int cont_neg = 0, cont_posi = 0, cont_cero = 0;
    int n, neg[101], posi[101], cero[101], tmp;
    cin>>n;
    for(int i = 0 ; i < n ; ++i){
        cin>>tmp;
        if(tmp == 0)cero[cont_cero++] = tmp;
        else if(tmp>0)posi[cont_posi++] = tmp;
        else neg[cont_neg++] = tmp;
    }

    if(cont_neg%2 == 0){
        cero[cont_cero++] = neg[--cont_neg];
    }

    if(cont_posi == 0){
        posi[cont_posi++] = neg[--cont_neg];
        posi[cont_posi++] = neg[--cont_neg];
    }

    cout<<cont_neg;
    for(int i = 0 ; i < cont_neg ; ++i){
        cout<<" "<<neg[i];
    }
    cout<<endl;
    cout<<cont_posi;
    for(int i = 0 ; i < cont_posi ; ++i){
        cout<<" "<<posi[i];
    }
    cout<<endl;
    cout<<cont_cero;
    for(int i = 0 ; i < cont_cero ; ++i){
        cout<<" "<<cero[i];
    }
    cout<<endl;

    return 0;
}
