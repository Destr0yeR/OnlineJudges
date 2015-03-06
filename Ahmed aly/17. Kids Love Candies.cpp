#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, k;
        cin>>n>>k;
        int total = 0;
        while(n--)
        {
            int c;
            cin>>c;
            total += c/k;
        }
        cout<<total<<endl;
    }
    return 0;
}
