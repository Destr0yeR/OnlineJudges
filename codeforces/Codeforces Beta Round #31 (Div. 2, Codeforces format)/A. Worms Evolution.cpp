#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int v[101];
    int a = 1, b = 1, c = 1;
    for(int i = 1 ; i <= n ; ++i)cin>>v[i];
    bool encontrado = false;
    //sort(v+1, v+1+n);

    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            for(int k = 1 ; k <= n ; ++k){
                if(i!=j && j!=k && i!=k){
                    if(v[i] + v[j] == v[k]){
                        a=i,b=j,c=k;
                        encontrado = true;
                        break;
                    }
                }
            }
            if(encontrado)break;
        }
        if(encontrado)break;
    }

    if(v[a] + v[b] == v[c]){
        cout<<c<<" "<<b<<" "<<a<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}
