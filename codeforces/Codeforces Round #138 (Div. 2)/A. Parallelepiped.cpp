#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
int main()
{
    ull a, b, c;
    cin>>a>>b>>c;

    ull multi = a*b*c;
    multi = sqrt(multi);

    ull x = multi/a;
    ull y = multi/b;
    ull z = multi/c;

    cout<<(x+y+z)*4<<endl;

    return 0;
}
