#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, r;
    cin>>a>>b>>r;
    if(2*r <= min(a,b)){
        cout<<"First"<<endl;
    }
    else{
        cout<<"Second"<<endl;
    }
    return 0;
}
