#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, tmp;
    bool v[3001];
    cin>>n;
    for(int i = 0 ; i < 3001 ; ++i)v[i] = false;
    while(n--){
        cin>>tmp;
        v[tmp] = true;
    }
    tmp = 3001;
    for(int i = 1 ; i <= 3000 ; i++){
        if(!v[i]){
            tmp=i;
            break;
        }
    }
    cout<<tmp<<endl;
    return 0;
}
