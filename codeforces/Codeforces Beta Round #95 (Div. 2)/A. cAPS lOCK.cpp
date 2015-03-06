#include<bits/stdc++.h>
#include<string>

using namespace std;

int main()
{
    string palabra;
    cin>>palabra;

    bool error = true;

    for(int i = 1 ; i < palabra.size() ; ++i)
    {
        if(palabra[i] >= 'a' && palabra[i] <= 'z')
        {
            error = false;
            break;
        }
    }
    if(error)
    {
        transform(palabra.begin()+1, palabra.end(), palabra.begin()+1 , ::tolower);
        if(palabra[0]>='a' && palabra[0]<= 'z')
        {
            palabra[0] = palabra[0] - 'a' + 'A';
        }
        else
        {
            palabra[0] = palabra[0] - 'A' + 'a';
        }
    }
    cout<<palabra<<endl;
    return 0;
}
