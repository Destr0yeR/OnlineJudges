#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<int, int> m;
    int n, tc, tmp;
    cin>>n;

    tc = n;

    while(tc--){
        cin>>tmp;
        m[tmp]++;
    }

    bool sePuede = true;

    for(map<int, int>::iterator it = m.begin() ; it != m.end() ; ++it){
        if((it->second) > ((n+1)/2)){
            sePuede = false;
            break;
        }
    }

    cout<<(sePuede?"YES":"NO")<<endl;

    return 0;
}
