#include<bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
    string a;
    cin>>a;

    int total = 1;

    char ante = 'c';

    for(int i = 0 ; i < a.size() ; ++i)
    {
        if(a[i] == ante)
        {
            total++;
            if(total == 7)break;
        }
        else
        {
            total = 1;
        }
        ante = a[i];
    }
    cout<<(total == 7 ? "YES":"NO")<<endl;
    return 0;
}
