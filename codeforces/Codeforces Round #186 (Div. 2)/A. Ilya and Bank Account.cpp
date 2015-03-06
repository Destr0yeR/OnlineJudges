#include<bits/stdc++.h>

using namespace std;

int main()
{
    int s;
    cin>>s;

    if(s < 0){
        int u = (-s)%10;
        int d = ((-s)%100)/10;


        s = s/10;

        if(u<d){
            s = s + d - u;
        }
    }

    cout<<s<<endl;

    return 0;
}
