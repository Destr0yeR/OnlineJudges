#include<bits/stdc++.h>

using namespace std;

int expo(int b, int e)
{
    if(e == 0) return 1;
    int tmp = b;
    for(int i = 2 ; i <= e ; ++i){
        tmp *=b;
    }
    return tmp;
}

int remove_cero(int x)
{
    int tmp = 0;

    int i = 0;
    while(x>0){
        int mod = x%10;
        if(mod != 0){
            tmp += mod * expo(10,i);
            i++;
        }
        x /= 10;
    }
    return tmp;
}

int main()
{
    int a, b;
    cin>>a>>b;
    int left = remove_cero(a+b);
    int right = remove_cero(a) + remove_cero(b);
    cout<<(left == right?"YES":"NO")<<endl;
    return 0;
}
