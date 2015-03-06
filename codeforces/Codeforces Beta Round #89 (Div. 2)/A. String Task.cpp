#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

int main()
{
    string palabra;
    cin>>palabra;
    transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);
    for(int i = 0 ; i < palabra.size() ; ++i)
    {
        switch(palabra[i])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
            break;
        default:
            cout<<"."<<palabra[i];
        }
    }
    cout<<endl;
    return 0;
}
