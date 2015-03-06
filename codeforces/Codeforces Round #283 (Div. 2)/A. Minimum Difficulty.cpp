#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int mini = 999999999;
    int maxi;
    int v[101];
    for(int i = 0 ; i < n ; ++i)cin>>v[i];

    for(int j = 1 ; j < n-1 ; ++j)
    {
        int maxi = 0;
        for(int i = 0 ; i < n-1 ; ++i)
        {
            if(i != j)
            {
                if(i+1 != j)
                {
                    maxi = max(v[i+1]-v[i],maxi);
                }
                else
                {
                    maxi = max(v[i+2]-v[i],maxi);
                }
            }
        }
        mini = min(maxi,mini);
    }
    cout<<mini<<endl;
    return 0;
}
