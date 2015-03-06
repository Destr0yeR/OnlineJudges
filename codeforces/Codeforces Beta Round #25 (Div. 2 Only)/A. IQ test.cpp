#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int v[101];
    int pares = 0;
    int impares = 0;
    int last_par = 0;
    int last_impar = 0;

    for(int i = 1 ; i <= n ; ++i){
        cin>>v[i];
        if(v[i]%2){
            pares++;
            last_par = i;
        }
        else{
            impares++;
            last_impar = i;
        }
    }

    if(pares == 1)cout<<last_par;
    else cout<<last_impar;

    cout<<endl;

    return 0;
}
