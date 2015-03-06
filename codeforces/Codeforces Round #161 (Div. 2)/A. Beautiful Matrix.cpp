#include<iostream>

using namespace std;

int main()
{
    int m[6][6];
    int a, b;

    for(int i = 1 ; i <= 5 ; ++i)
    {
        for(int j = 1 ; j <= 5 ; ++j)
        {
            cin>>m[i][j];
            if(m[i][j]!=0)
            {
                a = i;
                b = j;
            }
        }
    }


    int x = a - 3;
    int y = b - 3;

    if(x<0)x = -x;
    if(y<0)y = -y;

    cout<<x+y<<endl;

    return 0;
}
