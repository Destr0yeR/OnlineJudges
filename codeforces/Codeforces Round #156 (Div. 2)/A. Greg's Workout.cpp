#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, l, x = 0, y = 0, z = 0;
    cin>>n;
    for(int i = 0 ; i < n ; ++i){
        cin>>l;
        int mod = i%3;
        switch(mod){
            case 0:
                x+=l;
                break;
            case 1:
                y+=l;
                break;
            case 2:
                z+=l;
                break;
        }
    }
    if(x>y){
        if(x>z){
            cout<<"chest"<<endl;
        }
        else{
            cout<<"back"<<endl;
        }
    }
    else{
        if(y>z){
            cout<<"biceps"<<endl;
        }
        else{
            cout<<"back"<<endl;
        }
    }
    return 0;
}
