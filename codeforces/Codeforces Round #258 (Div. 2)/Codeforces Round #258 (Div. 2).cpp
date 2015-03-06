#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin>>a>>b;
    int x = min(a, b);

    cout<<(x%2 == 0? "Malvika":"Akshat")<<endl;
    return 0;
}
