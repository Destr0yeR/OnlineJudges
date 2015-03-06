#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    char x;
    char no_x;
    char in;
    bool isX = true;

    cin>>n;
    for(int i = 1; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            cin>>in;
            if(i==1 && j==1)x=in;
            if(i==1 && j==2)no_x=in;
            if(i == j){
                if(x != in)isX = false;
            }
            else if((n+1-i) == j){
                if(x != in)isX = false;
            }
            else{
                if(no_x != in)isX = false;
            }
        }
    }
    if(x==no_x)cout<<"NO"<<endl;
    else cout<<(isX?"YES":"NO")<<endl;
    return 0;
}
