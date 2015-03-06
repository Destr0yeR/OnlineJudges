#include<iostream>

using namespace std;

int main()
{
    int v[101];
    int x[101];
    int n;
    cin>>n;

    for(int i = 1 ; i <= n ; ++i)
    {
        int a;
        cin>>a;
        v[a] = i;
    }

    for(int i = 1 ; i <= n ; ++i)
    {
        cout<<v[i];
        if(i!=n)cout<<" ";
    }
    cout<<endl;
    return 0;
}
