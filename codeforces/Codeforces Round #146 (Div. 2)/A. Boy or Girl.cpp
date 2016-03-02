#include<bits/stdc++.h>

using namespace std;

int main(){

    bitset<27> v;
    v.reset();

    string s;
    int sz, cont = 0;

    cin >> s;

    sz = s.size();

    for(int i = 0 ;  i < sz ; ++i){
        if(v[s[i]-'a'] == 0){
            v[s[i]-'a'] = 1;
            cont ++;
        }
    }

    if(cont%2 == 0)cout << "CHAT WITH HER!\n";
    else cout << "IGNORE HIM!\n";

    return 0;
}
