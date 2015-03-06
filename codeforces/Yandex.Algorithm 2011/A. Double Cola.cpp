#include<bits/stdc++.h>

using namespace std;

/*
1 2 3 4 5 1 1 2 2  3  3  4  4  5  5  1  1  1  1  2  2  2  2  3  3  3  3  4  4  4  4  5  5  5  5
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35
0 0 0 0 0 1 1 1 1  1  1  1  1  1  1  2  2  2  2  2  2  2  2  2  2  2  2  2  2  2  2  2  2  2  2


*/
int logarithm(int x, int b)
{
    if(x == 1) return 0;
    return logarithm(x/b, b) + 1;
}

int main()
{
    int x;
    cin>>x;
    int med = x;
    int lg = logarithm((x+4)/5,2);
    int den = lg * 2 ;
    if(lg == 0)den = 1;
    int pt_ante = pow(2, lg);
    int rpta =  (x - (pt_ante -1 )* 5);
    int n = (rpta+pt_ante-1)/pt_ante;
    switch(n)
    {
    case 1:
        cout<<"Sheldon"<<endl;
        break;
    case 2:
        cout<<"Leonard"<<endl;
        break;
    case 3:
        cout<<"Penny"<<endl;
        break;
    case 4:
        cout<<"Rajesh"<<endl;
        break;
    case 5:
        cout<<"Howard"<<endl;
        break;
    }

    return 0;
}
