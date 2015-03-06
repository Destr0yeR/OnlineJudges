#include<bits/stdc++.h>

using namespace std;

int main()
{
    string palabra;
    cin>>palabra;
    bool encontrado = false;
    for(int i = 0 ; i < palabra.size() ; ++i)
    {
        if(palabra[i]=='H' || palabra[i]=='Q' || palabra[i]=='9')
        {
            encontrado = true;
            break;
        }
    }
    cout<<(encontrado?"YES":"NO")<<endl;
    return 0;
}
