#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ull k , m;
    cin>>k>>m;

    ull temp = k; int cont = 0;
    while(temp < m){
        temp *= k; cont++;
    }
    if(temp == m){
        cout<<"YES"<<endl<<cont<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
