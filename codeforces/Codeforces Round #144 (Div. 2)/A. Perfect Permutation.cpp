#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n%2 == 1)cout<<-1<<endl;
    else{
        for(int i = 1 ; i<n ; i+=2)
        {
            if(i!=1)cout<<" ";
            cout<<i+1<<" "<<i;
        }
        cout<<endl;
    }
    return 0;
}
