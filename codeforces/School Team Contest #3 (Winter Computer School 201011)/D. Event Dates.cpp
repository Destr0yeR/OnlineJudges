#include<bits/stdc++.h>

using namespace std;

struct par{
    long long l;
    long long r;
};

bool cmp(par a, par b){
    if(a.r == b.r){
        return a.l < b.l;
    }
    if(a.l == b.l){
        return a.r < b.r;
    }
    if(a.l < b.l){
        return a.r < b.r;
    }
    return a.r > b.r;
}

int main()
{
    //freopen(" - in.txt", "r", stdin);
    //freopen(" - out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n;
    cin>>n;

    int mem[10000000];

    cout << " bla" << endl;
    memset(mem, 0 , sizeof(mem));

    cout << "x" << endl;
    long long int l, r;

    par p[101];

    for(int i = 0 ; i < n ; ++i) {
        cin>>p[i].l>>p[i].r;
    }

    sort(p , p + n, cmp);
    int cont = 0;

    for(int i = 0 ; i < n ; ++i){
        cout<<p[i].l << " " << p[i].r << endl;
    }

    for(int i = 0 ; i < n && cont!=n; ++i){
        if(cont != 0) cout<<" ";
        int j;
        for(j = p[i].l ;  j <= p[i].r ; ++j){
            if(mem[j] == 0)break;
        }
        mem[j] = 1;
        cout<<j;
        cont++;
    }
    cout<<endl;
    return 0;
}
