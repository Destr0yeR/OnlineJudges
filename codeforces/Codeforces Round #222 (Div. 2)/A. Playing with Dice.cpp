#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    int maxi, mini;
    cin>>a>>b;
    if(a == b){
        cout<<"0 6 0"<<endl;
    }
    else{
        maxi = max(a,b);
        mini = min(a,b);

        int win_a = mini-0;
        int win_b = 7-maxi;
        int draw = 0;

        int mid = maxi-mini;
        if(mid%2 == 0)
        {
            draw = 1;
        }

        win_a += (mid-1)/2;
        win_b += (mid-1)/2;
        if(a<b)
        {
            cout<<win_a<<" "<<draw<<" "<<win_b<<endl;
        }
        else
        {
            cout<<win_b<<" "<<draw<<" "<<win_a<<endl;
        }
    }
    return 0;
}
