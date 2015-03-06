#include<bits/stdc++.h>

using namespace std;

int main()
{
    int posi = 1;
    string s;
    string t;
    cin>>s>>t;
    for(int i = 0 , j = 0; i < s.size() && j < t.size();++j){
        if(s[i] == t[j]){
            i++;
            posi++;
        }
    }
    cout<<posi<<endl;
    return 0;
}
