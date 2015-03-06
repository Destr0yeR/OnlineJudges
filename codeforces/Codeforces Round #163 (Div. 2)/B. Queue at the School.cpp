#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, t;
    cin>>n>>t;
    string q;
    cin>>q;
    while(t--){
        for(int i = 0 ; i < n ; ++i){
            if(q[i] == 'B'){
                if(q[i+1] == 'G'){
                    q[i] = 'G';
                    q[i+1] = 'B';
                    i++;
                }
            }
        }
    }
    cout<<q<<endl;
    return 0;
}
