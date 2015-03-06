#include<bits/stdc++.h>

using namespace std;

bool cmp(int a, int b)
{
    return a>b;
}

int main()
{
    int n, m, k, v[51];

    cin>>n>>m>>k;

    for(int i = 0 ; i < n ; ++i)cin>>v[i];

    sort(v, v + n, cmp);

    int sp = 0;
    int total = k;
    int j = 0;
    for(int i = 0 ; i < n ; ++i){
        if(total>=m)break;
        sp++;
        total--;
        total += v[i];
    }

    if(total>=m){
        cout<<sp<<endl;
    }
    else{
        cout<<-1<<endl;
    }

    return 0;
}
