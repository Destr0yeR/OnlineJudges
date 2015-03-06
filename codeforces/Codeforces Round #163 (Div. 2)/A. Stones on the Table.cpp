#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    char palabra[51];
    for(int i = 0 ; i < n ; ++i)cin>>palabra[i];

    char ante = 'c';
    int total = 0;
    for(int i = 0 ; i < n ; ++i)
    {
        if(palabra[i] == ante)
        {
            total++;
        }
        ante = palabra[i];
    }
    cout<<total<<endl;
    return 0;
}
