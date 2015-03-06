#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long a, b;

        b = 0;
        int N;
        cin>>N;
        while(N--)
        {
            cin>>a;
            while (a & 1)
            {
                a >>= 1;
            }
            b ^= a;
        }
        cout<<(b == 0 ? "NO" : "YES")<<endl;
    }
    return 0;
}
