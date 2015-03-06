#include<bits/stdc++.h>

using namespace std;

bool compare(int x, int y) {return (x>y);}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);

    int total = 0;

    while(n--)
    {
        int a;
        cin>>a;
        total += a;
        v.push_back(a);
    }

    sort(v.begin(), v.end(),compare);

    int monedas = 0;
    int suma = 0;

    for(vector<int>::iterator it = v.begin() ; it != v.end() ; ++it)
    {
        suma += *it;
        monedas++;
        if(2*suma > total)break;
    }

    cout<<monedas<<endl;

    return 0;
}
