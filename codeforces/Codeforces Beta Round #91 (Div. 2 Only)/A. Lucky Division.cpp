#include<iostream>

using namespace std;

bool check_lucky(int x)
{
    bool is = true;

    while(x>0)
    {
        int a = x%10;

        if(a != 4 && a != 7)
        {
            is = false;
            break;
        }

        x /= 10;
    }

    return is;
}


int main()
{
    int n;
    cin>>n;

    bool hay = false;

    for(int i = 1 ; i <= n ; ++i)
    {
        if(check_lucky(i))
        {
            if(n%i == 0)
            {
                hay = true;
                break;
            }
        }
    }

    cout<<(hay?"YES":"NO")<<endl;


    return 0;
}
