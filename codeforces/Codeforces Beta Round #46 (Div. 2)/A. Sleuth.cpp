#include<bits/stdc++.h>

using namespace std;

bool esVocal(char c)
{
    return (c =='a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

int main()
{
    string s;
    //cin.ignore(255,'\n');
    getline(cin,s);
    for(int i = s.size()-1 ; i >= 0 ; --i){
        char tmp = tolower(s[i]);
        if(tmp >= 'a' && tmp <= 'z'){
            if(esVocal(tmp)){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
            break;
        }
    }
    return 0;
}
