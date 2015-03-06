#include<bits/stdc++.h>

using namespace std;

string convert(int x)
{
    switch(x){
        case 0:
            return "O-|-OOOO";
            break;
        case 1:
            return "O-|O-OOO";
            break;
        case 2:
            return "O-|OO-OO";
            break;
        case 3:
            return "O-|OOO-O";
            break;
        case 4:
            return "O-|OOOO-";
            break;
        case 5:
            return "-O|-OOOO";
            break;
        case 6:
            return "-O|O-OOO";
            break;
        case 7:
            return "-O|OO-OO";
            break;
        case 8:
            return "-O|OOO-O";
            break;
        case 9:
            return "-O|OOOO-";
            break;
    }
}

int main()
{
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<convert(n)<<endl;
    }
    while(n>0){
        cout<<convert(n%10)<<endl;
        n /= 10;
    }
    return 0;
}
