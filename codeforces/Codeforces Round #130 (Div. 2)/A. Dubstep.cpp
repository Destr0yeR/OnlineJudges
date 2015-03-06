#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    bool v[200];
    cin>>s;

    int state = 0;
    int ini, mid, fin;

    for(int i = 0 ; i < s.size() ; ++ i)v[i]=false;

    for(int i = 0 ; i < s.size() ; ++i){
        switch(state){
            case 0:
                if(s[i] == 'W'){
                    state = 1;
                    ini = i;
                }
                else{
                    state = 0;
                }
                break;
            case 1:
                if(s[i] == 'U'){
                    state = 2;
                    mid = i;
                }
                else if(s[i] == 'W'){
                    state = 1;
                    ini = i;
                }
                else{
                    state = 0;
                }
                break;
            case 2:
                if(s[i] == 'B'){
                    state = 0;
                    fin = i;
                    v[ini] = true;
                    v[mid] = true;
                    v[fin] = true;
                }
                else if(s[i] == 'W'){
                    ini = i;
                    state = 1;
                }
                else
                {
                    state = 0;
                }
                break;
        }
    }

    int cont = 0;
    bool encontrado = false;
    bool printed = true;

    int cantidad = 0;

    bool contado = false;

    for(int i = 0 ; i < s.size() ; ++i)
    {
        if(!v[i])
        {
            if(!contado)
            {
                contado = true;
                cantidad++;
            }
        }
        else
        {
            contado = false;
        }
    }

    int escritos = 1;

    for(int i = 0 ; i < s.size() ; ++i)
    {
        if(!v[i])
        {
            encontrado = true;
            cout<<s[i];
            printed = false;
        }
        else
        {
            if(encontrado){
                if(!printed) {
                    printed = true;
                    if(escritos < cantidad){
                        cout<<" ";
                    }
                    escritos++;
                }
            }
        }
    }
    cout<<endl;
    return 0;
}
