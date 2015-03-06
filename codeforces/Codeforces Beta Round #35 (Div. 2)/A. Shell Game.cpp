#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, a, b;
    cin>>n;

    int atm = 3;
    while(atm--){
        cin>>a>>b;
        if(n == a)swap(n,b);
        else if(n == b)swap(n,a);
    }

    cout<<n<<endl;
    return 0;
}
