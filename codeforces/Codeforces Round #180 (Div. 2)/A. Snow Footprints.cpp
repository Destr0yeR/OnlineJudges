#include<iostream>

using namespace std;

int main()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    int a = -1, c = -1; bool L = false;
    int b = -1, d = -1;bool R = false;

    for(int i = 0 ; i < n ; ++i){
        if(s[i] == 'R'){
            if(!R){
             a = i;
             R = true;
            }
            c = i;
        }
        if(s[i] == 'L'){
            if(!L){
                b = i;
                L = true;
            }
            d = i;
        }
    }

    if(a == -1){
        cout<<d+1<<" "<<b<<endl;
    }
    else if(b == -1){
        cout<<a+1<<" "<<c+2<<endl;
    }
    else{
        cout<<a+1<<" "<<b<<endl;
    }
    return 0;
}
