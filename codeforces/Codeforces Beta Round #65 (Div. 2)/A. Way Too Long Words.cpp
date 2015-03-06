#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n;
    string palabra;
    cin>>n;
    while(n--)
    {
        cin>>palabra;
        int pSize = palabra.size();
        if(pSize > 10)cout<<palabra[0]<<pSize-2<<palabra[pSize-1];
        else cout<<palabra;
        cout<<endl;
    }
    return 0;
}
