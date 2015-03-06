#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int p;
    cin>>p;
    bool a[101];
    int tmp;
    int cont = 0 ;
    for(int i = 1 ; i <= n ; ++i)a[i] = false;
    for(int i = 1 ; i <= p ; ++i){
        cin>>tmp;
        if(!a[tmp])
        {
            a[tmp] = true;
            cont++;
        }
    }
    int q;
    cin>>q;
    for(int i = 1 ; i <= q ; ++i){
        cin>>tmp;
        if(!a[tmp])
        {
            a[tmp] = true;
            cont++;
        }
    }
    if(cont == n){
        cout<<"I become the guy."<<endl;
    }
    else {
        cout<<"Oh, my keyboard!"<<endl;
    }
    return 0;
}
