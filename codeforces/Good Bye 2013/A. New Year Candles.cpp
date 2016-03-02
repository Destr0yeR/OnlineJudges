#include<bits/stdc++.h>

using namespace std;

int main(){

    int a, b, cont = 0, r = 0;

    cin >> a >> b;

    do {
        cont += a;
        a = (a+r)/b;
        r = a%b;
        cout << a << endl;
    }
    while(a >= b);

    cont += a;

    cout << cont << endl;

    return 0;
}
