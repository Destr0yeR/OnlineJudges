#include<bits/stdc++.h>
#define inf 9999999999

using namespace std;

int num[201];
bool v[201];
int minimo = inf;

int n;

void reset()
{
    for(int i =  0; i < n ; ++i)v[i] = false;
}

void dp (int x)
{
    reset();

    int actual = x;
    v[x] = true;

    for(int i = x+1 ; i<n ; ++i)
    {
        for(int j = i ; j<n ; ++j)
        {
            if(num[actual] < num[j])
            {
                if(!v[j])
                {
                    v[j]=true;
                    actual = j;
                }
            }
        }
        for(int j = 0 ; j < n ; ++j)
        {

        }

        int temp = 0;
        for(int k = 0 ; k < n ; ++k)
        {
            if(!v[k])temp++;
        }
        if(temp<minimo){minimo = temp;}
        reset();
        v[x] = true;
        actual = x;
    }
}

int main()
{
    while(cin>>n)
    {
        minimo = inf;
        if(n==-1)break;
        for(int i = 0; i < n ; ++i)cin>>num[i];
        for(int i = 0 ; i<n ; ++i)dp(i);
        cout<<minimo<<endl;
    }


    return 0;
}
