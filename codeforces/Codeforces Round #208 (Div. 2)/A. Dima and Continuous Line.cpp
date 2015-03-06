#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int v[1001];
    cin>>n;
    for(int i = 0 ; i < n ; ++i)cin>>v[i];

    bool cruce = false;

    int x1, x2, x3, x4, aux;

    for(int i = 0 ; i < n - 1 ; ++i){
        x1 = v[i], x2 = v[i+1];
        if(x1 > x2)swap(x1, x2);

        for(int j = i+2 ; j < n - 1 ; ++j){
            x3 = v[j], x4 = v[j+1];
            if(x3 > x4)swap(x3, x4);
            //cout<<x1<<x2<<x3<<x4<<endl;
            if(x3 > x1 && x3<x2 && x4>x2){
                cruce = true;
                break;
            }
            else if( x4 < x2 && x4 > x1 && x3 < x1){
                cruce = true;
                break;
            }
        }
    }

    cout<<(cruce?"yes":"no")<<endl;

    return 0;
}
