#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int total = 0;
    while(n--)
    {
        int m = 3, temp = 0;
        while(m--)
        {
            int a;
            cin>>a;
            if(a == 1)temp++;
        }
        if(temp >= 2)total++;
    }
    cout<<total<<endl;
    return 0;
}
