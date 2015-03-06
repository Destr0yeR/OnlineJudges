#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    int max = 0;
    int temp;

    temp = a + b*c;
    if(temp>max)max = temp;
    temp = (a+b) * c;
    if(temp>max)max = temp;
    temp = a*b + c;
    if(temp>max)max = temp;
    temp = a * (b+c);
    if(temp>max)max = temp;
    temp = a*b*c;
    if(temp>max)max = temp;
    temp = a+b+c;
    if(temp>max)max = temp;
    cout<<max<<endl;
    return 0;
}
