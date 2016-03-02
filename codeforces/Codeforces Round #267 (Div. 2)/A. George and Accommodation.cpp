#include<bits/stdc++.h>

using namespace std;

int main(){

    int n, p, q, cont = 0;

    cin >> n;

    for(int i = 0 ; i < n ; ++i){
        cin >> p >> q;
        if(p + 2 <= q)cont++;
    }

    cout << cont << endl;

    return 0;
}
