#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    int posi = 1;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            if(i%2 == 0)cout<<"#";
            else{
                if(posi == i){
                    if(j == m-1){
                        cout<<"#";
                        posi+=4;
                    }
                    else cout<<".";
                }
                else{
                    if(j == 0)cout<<"#";
                    else cout<<".";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
