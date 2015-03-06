#include<bits/stdc++.h>

using namespace std;

int cuadrado(int x)
{
    return x*x;
}

bool pitagoras(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if(x1 == x2 && y1 == y2)return false;
    if(x1 == x3 && y1 == y3)return false;
    if(x2 == x3 && y2 == y3)return false;

    int a = cuadrado(abs(x1-x2))+cuadrado(abs(y1-y2));
    int b = cuadrado(abs(x1-x3))+cuadrado(abs(y1-y3));
    int c = cuadrado(abs(x2-x3))+cuadrado(abs(y2-y3));

    if(a == b+c)return true;
    if(b == a+c)return true;
    if(c == b+a)return true;

    return false;
}

int main()
{
    int x1, y1, x2, y2, x3, y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    if(pitagoras(x1,y1,x2,y2,x3,y3)){
        cout<<"RIGHT"<<endl;
        return 0;
    }

    int x[] = {-1,0,1,0};
    int y[] = {0,-1,0,1};

    for(int i = 0 ; i < 4 ; ++i){
        if(pitagoras(x1+x[i],y1+y[i],x2,y2,x3,y3)){
            cout<<"ALMOST"<<endl;
            return 0;
        }
    }

    for(int i = 0 ; i < 4 ; ++i){
        if(pitagoras(x1,y1,x2+x[i],y2+y[i],x3,y3)){
            cout<<"ALMOST"<<endl;
            return 0;
        }
    }

    for(int i = 0 ; i < 4 ; ++i){
        if(pitagoras(x1,y1,x2,y2,x3+x[i],y3+y[i])){
            cout<<"ALMOST"<<endl;
            return 0;
        }
    }

    cout<<"NEITHER"<<endl;

    return 0;
}
