#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m, tmp;
    long long last = 0;

    cin>>n>>m;
    long long total = 0;
    while(m--){
        cin>>tmp;
        if(tmp<last)total++;
        last = tmp;
    }

    long long rpta = last-1 + (total*n);

    cout<<rpta<<endl;

    return 0;
}
