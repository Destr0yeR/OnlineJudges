#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, tmp;
    cin>>n>>k;
    int total = 0;
    while(n--)
    {
        cin>>tmp;
        if(tmp<=(5-k)){
            total++;
        }
    }
    cout<<total/3<<endl;
    return 0;
}
