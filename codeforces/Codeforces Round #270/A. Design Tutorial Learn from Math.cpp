#include<bits/stdc++.h>
#define MAX 1000001

using namespace std;

bitset<MAX> b;

void sieve(){
    b.set();
    b[0] = 0;
    b[1] = 0;
    for(int i = 4 ; i < MAX ; i+=2)b[i] = 0;

    int sq = sqrt(MAX);

    for(int i = 3 ; i <= sq ; i+=2)if(b[i] == 1)for(int j = i ; j*i < MAX ; j+=2)b[i*j] = 0;

}

int main(){
    sieve();

    int n, r;

    cin >> n;

    for(int i = 4 ; ; ++i){
        if(b[i] == 0){
            r = n-i;
            if(r < i)break;
            if(b[r] == 0){
                cout << i << " " << r << endl;
                break;
            }
        }
    }

    return 0;
}
