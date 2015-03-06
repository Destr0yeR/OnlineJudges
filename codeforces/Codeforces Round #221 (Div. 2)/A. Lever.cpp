#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long left = 0, right = 0;
    string s;
    cin>>s;

    int posi;

    bool L = true;

    for(int i = 0 ; i < s.size() ; ++i){
        if(s[i] == '^')posi=i;
    }

    for(int i = 0 ; i < s.size() ; ++i){
        if(s[i] == '^')L=false;
        else if(s[i] != '^' && s[i] != '='){
            if(L){
                left += (s[i]-'0')*(posi-i);
            }else{
                right += (s[i]-'0')*(i-posi);
            }
        }
    }

    if(left > right)cout<<"left"<<endl;
    else if(left < right)cout<<"right"<<endl;
    else cout<<"balance"<<endl;


    return 0;
}
