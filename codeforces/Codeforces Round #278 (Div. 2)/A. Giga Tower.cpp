#include<bits/stdc++.h>

using namespace std;

bool isLucky(int x)
{
    if(x<0)x=-x;
    bool isL = false;

    while(x>0){
        int mod = x%10;
        if(mod == 8){
            isL = true;
            break;
        }
        x /= 10;
    }

    return isL;
}

int main()
{
    int n;
    cin>>n;
    int total = 0;
    do
    {
        total++;
    }
    while(!isLucky(n+total));
    cout<<total<<endl;
    return 0;
}
