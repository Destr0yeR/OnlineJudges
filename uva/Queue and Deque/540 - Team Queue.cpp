#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

struct elemento{
    int val;
    int team;
    int pos;

    bool operator<(elemento b)const{
        if(team != b.team)return team<b.team;
        return pos<b.pos;
    }
};

int main()
{
    //freopen("540 - in.txt","r",stdin);
    //freopen("540 - out.txt","w",stdout);
    vector<int> v(1000000);
    set<elemento> q;
    set<elemento>::iterator it;
    int t, n, tmp, tc = 1;
    string s;
    while(cin>>t){
        if(!t)break;
        v.clear();
        q.clear();
        for(int i = 0 ; i < t ; ++i){
            cin>>n;
            for(int j = 0 ; j < n ; ++j){
                cin>>tmp;
                v[tmp] = i;
            }
        }

        int prioridad[1000];
        int cantidad[1000];
        int posi[1000];
        int cont = 0;

        for(int i = 0 ; i < t ; ++i){
            cantidad[i] = 0;
            posi[i] = 0;
        }
        cout<<"Scenario #"<<tc<<endl;
        while(cin>>s){
            if(s[0] == 'S'){
                break;
            }
            else{
                if(s[0] == 'E'){
                    cin>>tmp;
                    if(cantidad[v[tmp]] == 0){
                        cantidad[v[tmp]] = 1;
                        posi[v[tmp]]++;
                        prioridad[v[tmp]] = cont;
                        elemento e;
                        e.val = tmp;
                        e.team = prioridad[v[tmp]];
                        e.pos = posi[v[tmp]];
                        q.insert(e);
                        cont++;
                    }
                    else{
                        cantidad[v[tmp]]++;
                        posi[v[tmp]]++;
                        elemento e;
                        e.val = tmp;
                        e.team = prioridad[v[tmp]];
                        e.pos = posi[v[tmp]];
                        q.insert(e);
                    }
                }
                else{
                    it = q.begin();
                    cout<<(*it).val<<endl;
                    cantidad[v[(*it).val]]--;
                    q.erase(it);
                }
            }
        }
        tc++;
        cout<<endl;
    }


    return 0;
}
