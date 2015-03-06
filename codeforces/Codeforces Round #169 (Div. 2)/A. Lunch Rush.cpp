#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, f, t;
    cin>>n>>k;
    int maxi = -9999999999;
    for(int i = 0 ; i < n ; ++i){
        cin>>f>>t;
        if(t>k){
            maxi = max(maxi, f - (t-k));
        }
        else{
            maxi = max(maxi, f);
        }
    }
    cout<<maxi<<endl;
    return 0;
}
