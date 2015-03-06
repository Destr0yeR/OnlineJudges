#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s, t;
    cin>>s>>t;
    if(s.size() == t.size()){
        bool iguales = true;
        for(int i = 0 ; i < s.size() ; ++i){
            if(s[i] != t[s.size()-1-i]){
                iguales = false;
                break;
            }
        }
        if(iguales)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
    return 0;
}
