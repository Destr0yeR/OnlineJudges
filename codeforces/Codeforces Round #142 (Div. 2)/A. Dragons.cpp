#include<bits/stdc++.h>

using namespace std;

struct Dragon{
    int str;
    int posi;
};

bool cmp(Dragon a, Dragon b){
    return a.str < b.str;
}

int main()
{
    int s, n;
    cin>>s>>n;
    Dragon x[1001];
    int y[1001];

    for(int i = 1 ; i <= n ; ++i){
        cin>>x[i].str>>y[i];
        x[i].posi = i;
    }

    sort(x + 1, x + n + 1, cmp);

    bool pierde = false;

    for(int i = 1 ; i <= n ; ++i){
        if(s <= x[i].str){
            pierde = true;
            break;
        }
        else{
            s += y[x[i].posi];
        }
    }
    if(pierde)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
