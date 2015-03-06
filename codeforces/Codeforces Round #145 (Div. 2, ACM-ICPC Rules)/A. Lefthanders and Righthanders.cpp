#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    char e[101];
    for(int i = 1 ; i <= n ; ++i)cin>>e[i];

    n /=2;

    for(int i = 1 ; i <= n ; ++i){
        if(e[i] == e[i + n])
        {
            cout<<i<<" "<<i+n<<endl;
        }
        else{
            if(e[i] == 'R'){
                cout<<i+n<<" "<<i<<endl;
            }
            else{
                cout<<i<<" "<<i+n<<endl;
            }
        }
    }

    return 0;
}
