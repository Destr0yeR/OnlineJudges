#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int d;
    cin>>n>>d;
    int tiempo = 0;
    int total  = 0;
    while(n--){
        int t;
        cin>>t;
        tiempo += t;
        total++;
    }

    int rpta = 2*(total-1);

    int medio = tiempo + 5*(rpta);

    if(medio>d){
        cout<<-1<<endl;
    }
    else{
        rpta += (d-medio)/5;

        cout<<rpta<<endl;
    }

    return 0;
}
