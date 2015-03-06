#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int mini = 100;
    int posiMaxi;
    int maxi = 0;
    int posiMini;
    int i = n;
    for(int i = 1 ; i <= n ; ++i)
    {
        int a;
        cin>>a;
        if(a>maxi)
        {
            maxi = a;
            posiMaxi = i;
        }
        if(a<=mini)
        {
            mini = a;
            posiMini = i;
        }
    }
    int rpta = n + posiMaxi - posiMini - 1;
    if(posiMaxi>posiMini)rpta--;
    cout<<rpta<<endl;
    return 0;
}
