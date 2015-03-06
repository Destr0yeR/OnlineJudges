#include<bits/stdc++.h>

using namespace std;

int S(int n)
{
    int tmp = 0;

    while(n>0){
        tmp += n%10;
        n /= 10;
    }

    return tmp;
}

int S(string n)
{
    int tmp = 0;

    for(int i = 0 ; i < n.size() ; ++i){
        tmp += n[i]-'0';
    }

    return tmp;
}

int d(string n)
{
    int x = S(n);
    while( x >10){
        x = S(x);
    }
    return x;
}

int main()
{
    int k, d;
    cin>>k>>d;

    if(k>1 && d==0)cout<<"No solution"<<endl;
    else{
        cout<<d;
        for(int i = 1 ; i < k ; ++i){
            cout<<0;
        }
        cout<<endl;
    }

    return 0;
}
