#include<bits/stdc++.h>

using namespace std;

bool isLucky(int n){
    if(n == 0)return false;
    int r;
    while(n > 0){
        r = n%10;
        if(r != 4 && r != 7)return false;
        n /= 10;
    }
    return true;
}

int main(){
    string s;
    int sz, cont = 0;

    cin >> s;

    sz = s.size();

    for(int i = 0 ; i < sz ; ++i){
        if(isLucky(s[i] - '0'))cont ++;
    }

    if(isLucky(cont))cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
