#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
int main()
{
    ull n, k;

    while(cin>>n>>k){

    ull x = (n+1)/2;

    if(k <= x){
        cout<<2*k -1<<endl;
    }
    else{
        cout<<2*(k-x)<<endl;
    }
    }
    return 0;
}
