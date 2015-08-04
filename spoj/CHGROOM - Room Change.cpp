#include<bits/stdc++.h>
#define MAX 10000001

using namespace std;

bitset<MAX + 1> bs;
vector<long long> v;

void sieve(){
    bs.set();
    bs[0] = bs[1] = 0;
    for(long long i = 2; i <= MAX; i++){
        if(bs[i]){
            v.push_back(i);
            for(long long j = i*i; j <= MAX; j+=i) bs[j] = 0;
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    sieve();
    long long q;

    cin >> q;

    if(q == 1){
        cout << "ANNE" << endl;
        return 0;
    }
    long long divisores = 0;

    for(long long i = 0; i < v.size() && divisores <= 2 && v[i]*v[i] <= q;){
        if(q % v[i] == 0){
            divisores++;
            q/=v[i];
        }
        else ++i;
    }

    string rpta = "ANNE";
    if(divisores == 1) rpta = "MARIAN";
    cout << rpta << endl;

    return 0;
}
