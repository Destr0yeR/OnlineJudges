#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int v[101];
    cin>>n;
    int x, y, a, b, tmp;
    int mini = 9999999999;
    for(int i  = 0 ;  i < n ; ++i)cin>>v[i];

    for(int i  = 0 ;  i < n ; ++i){
        a=i, b=i+1;
        if(i == n-1)b=0;
        tmp = v[a]-v[b];
        if(tmp<0)tmp =-tmp;
        if(mini>tmp){
            mini=tmp;
            x=a;
            y=b;
        }
    }
    cout<<x+1<<" "<<y+1<<endl;
    return 0;
}
