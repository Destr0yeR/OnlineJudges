#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int x = 0;
    string linea;
    while(n--)
    {
        cin>>linea;
        if(linea[1] == '+')x++;
        if(linea[1] == '-')x--;
    }

    cout<<x<<endl;
    return 0;
}
