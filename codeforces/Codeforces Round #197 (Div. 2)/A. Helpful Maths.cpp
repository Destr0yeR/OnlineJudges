#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
    string s;
    cin>>s;
    map<int, int> numeros;
    int cantidad = 0;

    for(int i = 0 ; i < s.size() ; i+=2)
    {
        numeros[int(s[i]-'0')]++;
        cantidad++;
    }
    int cont = 0;
    for(map<int, int>::iterator it = numeros.begin() ; it != numeros.end() ; ++it)
    {
        while(it->second--)
        {
            cout<<it->first;
            if(!(cont == cantidad -1))cout<<"+";
            cont++;
        }
    }

    return 0;
}
