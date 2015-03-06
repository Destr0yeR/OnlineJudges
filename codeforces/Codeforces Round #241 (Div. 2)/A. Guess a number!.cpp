#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    long long a = -2000000000 , b = 2000000000 , tmp;
    cin>>n;
    string op;
    char rpta;
    while(n--)
    {
        cin>>op>>tmp>>rpta;
        if(op.size() == 2){
            if(rpta == 'Y'){
                if(op[0] == '>'){
                    if(tmp>a)a=tmp;
                }
                else{
                    if(tmp<b)b=tmp;
                }
            }
            else{
                if(op[0] == '>'){
                    if(tmp-1<b)b=tmp-1;
                }
                else{
                    if(tmp+1>a)a=tmp+1;
                }
            }
        }
        else{
            if(rpta == 'Y'){
                if(op[0] == '>'){
                    if(tmp+1>a)a=tmp+1;
                }
                else{
                    if(tmp-1<b)b=tmp-1;
                }
            }
            else{
                if(op[0] == '>'){
                    if(tmp<b)b=tmp;
                }
                else{
                    if(tmp>a)a=tmp;
                }
            }
        }
    }
    if(a>b)cout<<"Impossible"<<endl;
    else cout<<a<<endl;
    return 0;
}
