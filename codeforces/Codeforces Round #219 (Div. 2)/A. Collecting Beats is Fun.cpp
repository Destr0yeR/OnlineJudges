#include<bits/stdc++.h>
#include<string>

using namespace std;

int main()
{
    int k;
    cin>>k;
    int v[10];
    for(int i = 0 ; i<10 ; ++i)v[i] = 0;
    string s;
    for(int i = 0; i < 4; i++){
        cin>>s;
        for(int j = 0; j < 4; j++){
            if(s[j] != '.'){
                v[s[j]-'0']++;
            }
        }
    }

    bool sol = true;
    for(int i = 1; i <= 9; i++){
        if(v[i]>2*k){
            sol = false;
        }
    }
    if(sol){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}
