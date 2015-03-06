#include<bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
    string s;
    map<char, int> m;
    getline(cin, s);

    for(int i = 0 ; i < s.size() ; ++i){
        if((s[i] >= 'a' && s[i] <= 'z'))
        {
            m[s[i]]++;
        }
    }
    cout<<m.size()<<endl;
    m.clear();
    return 0;
}
