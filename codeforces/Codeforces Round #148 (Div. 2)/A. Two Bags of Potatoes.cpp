#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x, y, k, n;
    cin>>y>>k>>n;
    int cont = 0;
    int tmp = k;
    int i = 1;
    while(tmp<y)tmp = i*k,++i;
    x = tmp-y;

    if(x == 0)x=k;

    for( ; x + y <= n ; ){
        if((x+y)%k == 0){
            if(cont>0)cout<<" ";
            cout<<x;
            x += k;
            cont++;
        }
        else{
            x++;
        }
    }
    cout<<(cont==0?"-1":"")<<endl;

    return 0;
}
