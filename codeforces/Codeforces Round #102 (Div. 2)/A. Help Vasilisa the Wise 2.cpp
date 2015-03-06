#include<bits/stdc++.h>

using namespace std;

int main()
{
    int r1, r2, c1, c2, d1, d2, x1, x2, x3, x4;

    cin>>r1>>r2>>c1>>c2>>d1>>d2;

    x1 = ((r1+c1)-d2)/2;
    x2 = ((r1+c2)-d1)/2;
    x3 = ((r2+c1)-d1)/2;
    x4 = ((r2+c2)-d2)/2;

    if(((r1+r2+c1+c2+d1+d2)== (x1+x2+x3+x4)*3) && (x1!=x2 && x1!=x3 && x1!=x4 && x2!=x3 && x2!=x4 && x3!=x4) &&(x1<10&&x2<10&&x3<10&&x4<10)&&(x1>0&&x2>0&&x3>0&&x4>0)){
        cout<<x1<<" "<<x2<<endl;
        cout<<x3<<" "<<x4<<endl;
    }
    else{
        cout<<-1<<endl;
    }

    return 0;
}
