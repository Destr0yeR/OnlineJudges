#include<bits/stdc++.h>

using namespace std;

int main()
{
    int r, c;
    cin>>r>>c;
    char n;

    bool x[10];
    bool y[10];

    int total_x = 0;
    int total_y = 0;

    for(int i = 0 ; i < 10 ; ++i){
        x[i] = y[i] = false;
    }

    for(int i = 0 ; i < r ; ++i){
        for(int j = 0 ; j < c ; ++j){
            cin>>n;
            if(n=='S')
            {
                if(!x[j])
                {
                    x[j] = true;
                    total_x++;
                }
                if(!y[i])
                {
                    y[i] = true;
                    total_y++;
                }
            }
        }
    }
    int a = r-total_y;
    int b = c-total_x;
    int rpta = a*b + a*total_x + b*total_y;

    cout<<rpta<<endl;
    return 0;
}
