#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s, t;
    cin>>s>>t;
    if(s.size() == t.size())
    {
        int total = 0;
        bool diff = false;
        char c1, c2;
        for(int i = 0 ; i < s.size(); ++i)
        {
            if(s[i] != t[i]){
                if(total == 0){
                    c1 = s[i];
                    c2 = t[i];
                }
                if(total == 1){
                    if(c1 != t[i] || c2 != s[i])diff=true;
                }
                total++;
            }
        }
        if(total == 2 && !diff)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}
