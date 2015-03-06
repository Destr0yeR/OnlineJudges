#include<bits/stdc++.h>

using namespace std;

int convert(char s){
    return s-'0';
}

int main()
{
    int n, m;
    cin>>n>>m;
    string s[101];
    bool   v[101];
    int    r[101];
    for(int i = 0 ; i < n ; ++i)cin>>s[i];
    for(int i = 0 ; i < n ; ++i)v[i]=false;

    for(int j = 0 ; j < m ; ++j){
        int max = 0;
        for(int i = 0 ; i < n ; ++i){
            int x = convert(s[i][j]);
            if(x>max)max=x;
        }
        r[j] = max;
    }


    for(int j = 0 ; j < m ; ++j){
        for(int i = 0 ; i < n ; ++i){
            int x = convert(s[i][j]);
            if(x == r[j]){
                v[i]=true;
            }
        }
    }

    int total = 0;

    for(int i = 0 ; i < n ; ++i){
        if(v[i])total++;
    }

    cout<<total<<endl;
    return 0;
}
