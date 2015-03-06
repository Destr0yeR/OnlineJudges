#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, c;
    int ante, actual;
    cin>>n>>c;
    int maxi = 0;

    ante = 0;

    for(int i = 0 ; i < n ; ++i){
        cin>>actual;
        maxi = max(maxi, ante-actual-c);
        ante = actual;
    }
    cout<<maxi<<endl;
    return 0;
}
