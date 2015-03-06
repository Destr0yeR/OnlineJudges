#include<bits/stdc++.h>

using namespace std;

int main()
{
    int p, count = 0;
    cin>>p;
    for (int n = 1; n < p; ++n){
        bool encontrado = true;
        int x = 1;
        for (int i = 1; i < p - 1; ++i){
            x *= n;
            x %= p;
            if (x == 1){
                encontrado = false;
                break;
            }
        }
        if (encontrado){
            x *= n;
            x %= p;
            if (x == 1){
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}
