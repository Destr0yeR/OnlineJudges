#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, d, q, k;
    bool comprable;
    cin>>n>>d;
    vector<int> v(51);
    int cont = 0;
    for(int i =  1 ; i <= n ; ++i){
        cin>>k;
        comprable = false;
        for(int j = 1 ; j <= k ; ++j){
            cin>>q;
            if(q < d)
            {
                comprable = true;
            }
        }
        if(comprable)
        {
            v[cont] = i;
            cont++;
        }
    }
    int tc = 0;
    if(!cont)cout<<"0";
    else{
        cout<<cont<<endl;
        for(int i = 0 ; i < cont ; ++i){
            if(tc){
                cout<<" ";
            }
            cout<<v[i];
            tc++;
        }
    }
    cout<<endl;
    return 0;
}
