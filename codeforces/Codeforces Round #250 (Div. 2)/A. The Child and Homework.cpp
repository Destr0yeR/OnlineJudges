#include<bits/stdc++.h>

using namespace std;

struct opcion{
    string s;
    char rpta;

    bool operator<(const opcion &e) const{
        return s.size() < e.s.size();
    }
}v[4];

int main()
{
    cin>>v[0].s>>v[1].s>>v[2].s>>v[3].s;
    v[0].rpta = 'A';
    v[1].rpta = 'B';
    v[2].rpta = 'C';
    v[3].rpta = 'D';
    sort(v, v + 4);
    if((v[0].s.size()-2)*2 <= v[1].s.size()-2){
        if(v[3].s.size()-2 >= (v[2].s.size()-2)*2){
            cout<<"C"<<endl;
        }
        else cout<<v[0].rpta<<endl;
    }
    else if(v[3].s.size()-2 >= (v[2].s.size()-2)*2){
        if((v[0].s.size()-2)*2 <= v[1].s.size()-2){
            cout<<"C"<<endl;
        }
        else cout<<v[3].rpta<<endl;
    }
    else {
        cout<<"C"<<endl;
    }


    return 0;
}
