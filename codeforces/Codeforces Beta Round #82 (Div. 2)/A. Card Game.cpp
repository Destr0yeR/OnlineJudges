#include <bits/stdc++.h>

using namespace std;

int main()
{
    char tp;
    string f, s;

    map<char, int> r;

    r['6'] = 1;
    r['7'] = 2;
    r['8'] = 3;
    r['9'] = 4;
    r['T'] = 5;
    r['J'] = 6;
    r['Q'] = 7;
    r['K'] = 8;
    r['A'] = 9;


    cin>>tp;
    cin>>f>>s;

    if(s[1] == f[1]){
        if(r[f[0]] > r[s[0]])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else{
        if(f[1] == tp)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
