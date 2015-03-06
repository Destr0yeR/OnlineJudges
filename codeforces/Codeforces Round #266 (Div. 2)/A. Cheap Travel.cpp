#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a, b;
    cin>>n>>m>>a>>b;
    int rpta;
    int total = 0;
    int cantidad;

    if(m*a >= b){
        rpta = n/m;
        total = rpta*b;
        cantidad = rpta*m;
    }
    else{
        rpta = n;
        total = a*n;
        cantidad = n;

    }

    int mid = n - cantidad;

    if(mid > 0){
        if(a*mid>=b){
            total += b;
        }
        else{
            total += a * mid;
        }
    }
    cout<<total<<endl;
    return 0;
}
