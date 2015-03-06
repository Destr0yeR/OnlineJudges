#include<bits/stdc++.h>

using namespace std;

int puntuation(int p, int t)
{
    return max((3*p)/10, p-(p*t)/250);
}

int main()
{
    int a, b, c, d;
    cin>>a>>b>>c>>d;

    int m = puntuation(a,c);
    int v = puntuation(b,d);

    if(m == v){
        cout<<"Tie";
    }else if(m>v){
        cout<<"Misha";
    }else{
        cout<<"Vasya";
    }
    cout<<endl;

    return 0;
}
