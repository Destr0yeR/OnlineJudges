#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, l, c, d, p, nl, np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;

    int mini = 99999999999;

    mini = min(mini,(k*l)/nl);
    mini = min(mini,c*d);
    mini = min(mini,p/np);

    cout<<mini/n<<endl;

    return 0;
}
