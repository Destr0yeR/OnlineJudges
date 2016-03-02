#include<bits/stdc++.h>

using namespace std;

int main(){

    float a, b, c, d;

    cin >> a >> b >> c >> d;

    b-=a;

    c+=d;

    printf("%.6f\n", b/c);

    return 0;
}
