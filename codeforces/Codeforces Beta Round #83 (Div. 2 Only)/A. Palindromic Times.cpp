#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

int expo(int b, int e)
{
    if(e == 0)return 1;
    int tmp = b;

    for(int i = 2 ; i <= e ; ++i)tmp*=b;

    return tmp;
}

long long invert(long long x)
{
    long long tmp = 0;
    long long i = 0, mod;
    while(x>0){
        mod = x%10;
        tmp *= 10;
        tmp +=mod;
        i++;
        x /= 10;
    }

    return tmp;
}

int main()
{
    map<int, string> m;
    m[0] = "00:00";m[6]  = "10:01";m[12] = "12:21";m[18] = "20:02";
    m[1] = "01:10";m[7]  = "10:01";m[13] = "13:31";m[19] = "20:02";
    m[2] = "02:20";m[8]  = "10:01";m[14] = "14:41";m[20] = "20:02";
    m[3] = "03:30";m[9]  = "10:01";m[15] = "15:51";m[21] = "21:12";
    m[4] = "04:40";m[10] = "10:01";m[16] = "20:02";m[22] = "22:22";
    m[5] = "05:50";m[11] = "11:11";m[17] = "20:02";m[23] = "23:32";

    int hh, mm, tmp;

    scanf("%d:%d",&hh,&mm);

    if(hh >= 6 && hh <= 9){
        cout<<m[hh]<<endl;
        return 0;
    }
    if(hh >= 16 && hh <= 19){
        cout<<m[hh]<<endl;
        return 0;
    }

    tmp = invert(hh);
    if(hh<10)tmp*=10;
    if(tmp>mm){
        cout<<m[hh]<<endl;
    }
    else{
        if(hh == 23)cout<<m[0]<<endl;
        else cout<<m[hh+1]<<endl;
    }

    return 0;
}
