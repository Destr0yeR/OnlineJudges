#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n, a, b, c, i, j, drpta;
    cin>>n>>a>>b>>c;
    int max=0;
    for(i=0;i*a<=n;i++)
    {
        for(j=0;i*a+j*b<=n;j++)
        {
            if((n-i*a-j*b)%c==0)
            {
                if(i+j+(n-i*a-j*b)/c>max)
                max=i+j+(n-i*a-j*b)/c;
            }
        }
    }
    cout<<max<<endl;

    return 0;
}
