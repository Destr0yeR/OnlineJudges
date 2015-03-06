#include<iostream>

using namespace std;

int main()
{
    int n;
    int a, b, maxi = 0, capacity = 0;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        capacity = capacity -a + b;
        if(capacity>maxi)maxi = capacity;
    }
    cout<<maxi<<endl;
    return 0;
}
