#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio( 0 );
    int n,x=-1;
    string a;
    map<string,int> m;
    cin>>n;
    while(n--){
        cin>>a;
        m[a]++;
    }
    if(m.size()==1){
        cout<<a<<endl;
    }else{
        for(map<string,int>::iterator it=m.begin();it!=m.end();++it){
            if(it->second>x){
                x=it->second;
                a=it->first;
            }
        }
        cout<<a<<endl;
    }
    return 0;
}
