#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    map<int, int> cantidad;

    for(int i = 0 ; i < n ; ++i)
    {
        int a;
        cin>>a;
        cantidad[a]++;
    }
    int total = 0;
    total += cantidad[4];

    int temp = min(cantidad[1],cantidad[3]);
    total += temp;
    cantidad[1] -= temp;
    cantidad[3] -= temp;

    temp = cantidad[2]/2;
    total += temp;
    cantidad[2] -= 2*temp;

    if(cantidad[3]>0)
    {
        total += cantidad[3];
    }

    temp = min(cantidad[1], cantidad[2]);
    total += temp;
    cantidad[1] -= 2*temp;
    cantidad[2] -= temp;

    if(cantidad[1]>0)
    {
        total += (cantidad[1]+3)/4;
    }
    if(cantidad[2]>0)
    {
        total += cantidad[2];
    }

    cout<<total<<endl;

    return 0;
}
