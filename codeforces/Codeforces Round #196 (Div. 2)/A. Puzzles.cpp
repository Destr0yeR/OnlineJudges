#include<bits/stdc++.h>

using namespace std;
const int inf = numeric_limits<int>::max();

int main()
{
    int n, m;
    int p[51];

    cin>>n>>m;

    for(int i = 0 ; i < m ; ++i)
    {
        cin>>p[i];
    }
    sort(p, p + m);

    int min = inf;


    for(int i = 0 ; i < m - n + 1; ++i)
    {
        int diff = p[i+n-1] - p[i];
        if( diff < min)min=diff;
    }

    cout<<min<<endl;
    return 0;
}
