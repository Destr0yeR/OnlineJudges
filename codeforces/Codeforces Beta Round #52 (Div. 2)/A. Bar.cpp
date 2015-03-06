#include<bits/stdc++.h>

using namespace std;

int convert(string s)
{
    int tmp = 0;
    for(int i = 0 ; i < s.size(); ++i){
        tmp *= 10;
        tmp += int(s[i] - '0');
    }
    return tmp;
}

int main()
{
    map<string, bool> m;
    int n;
    cin>>n;

    m["ABSINTH"]   = true, m["BEER"]    = true, m["BRANDY"] = true;
    m["CHAMPAGNE"] = true, m["GIN"]     = true, m["RUM"] = true;
    m["SAKE"]      = true, m["TEQUILA"] = true, m["VODKA"] = true;
    m["WHISKEY"]   = true, m["WINE"]     = true;

    int total = 0, tmp;
    string s;
    while(n--){
        cin>>s;
        if(!m[s]){
            if(s[0]>='0' && s[0]<='9'){
                tmp = convert(s);
                if(tmp<18)total++;
            }
        }
        else{
            total++;
        }
    }

    cout<<total<<endl;

    return 0;
}
