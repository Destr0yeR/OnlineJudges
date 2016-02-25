#include<bits/stdc++.h>

using namespace std;

bool f(long long n){
    bitset<11> b;
    b.reset();
    long long r;

    while(n){
        r = n%10;
        if(b[r] == 1)return false;
        b[r] = 1;
        n/=10;
    }
    return true;
}

int main(){
    long long n;

    cin >> n;

    while(!f(++n)){

    }

    cout << n << endl;

    return 0;
}
