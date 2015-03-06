#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m[100][100];
    int n;
    cin>>n;
    char op;

    for(int i =  0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            m[i][j] = 0;
        }
    }

    for(int i =  0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            cin>>op;
            if(op == 'o'){
                for(int k = -1 ; k <= 1 ; ++k)
                {
                    for(int l = -1 ; l <= 1 ; ++l){
                        if(i==k+i || j == l+j)
                            if(!(k==0 && l==0))
                                m[i+k][j+l]++;
                    }
                }
            }
        }
    }

    bool pares = true;

    for(int i =  0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            //cout<<m[i][j]<<" ";
            if(m[i][j]%2 == 1){
                pares = false;
                break;
            }
        }
        //cout<<endl;
    }

    if(pares)cout<<"YES";
    else cout<<"NO";
    cout<<endl;

    return 0;
}
