#include <bits/stdc++.h>
using namespace std;

#define DEBUG
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back

typedef unsigned long long ull;


int bs(int _find , int a[], int n){
    int cont = 0;

    int index = -1;
    int mid;
    int l = 0;
    int r = n+1;

    while(r != l) {
        mid = (r+l)/2;

        if(a[mid] == _find){
            index = mid;
            cont++;
            break;
        }
        else if(a[mid] > _find){
            r = mid;
        }
        else {
            l = mid;
        }
    }
    if(index == -1){
        return 0;
    }

    for(int i = index+1 ; i <= n ; ++i){
        if(a[i] == _find){
            cont++;
        }
        else{
            break;
        }
    }
    for(int i = index-1 ; i >= 0 ; --i){
        if(a[i] == _find){
            cont++;
        }
        else{
            break;
        }
    }

    return cont;
}

int main()
{
    int n;
    cin >> n;
    int a[n+2];
    int acum[n+2];
    bool zero = true;
    a[0]    = 0;
    acum[0] = 0;
    a[n+1]  = 0;
    acum[n+1]= 0;

    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
        if(a[i] != 0)zero = false;
    }

    for(int i = 1 ; i <= n ; ++i){
        acum[i] = acum[i-1] + a[i];
    }

    a[0]    = -1000;
    acum[0] = -1000;
    a[n+1]  = -1000;
    acum[n+1]=-1000;;

    if(acum[n] % 3 != 0 || n <= 2){
        cout << 0 << endl;
    }
    else if(zero){
        cout << ((n-2)*(n-1))/2<< endl;
    }
    else {
        int x = acum[n]/3;
        int x2 = 2*acum[n]/3;

        int a = bs(x, acum, n);
        int b = bs(x2, acum, n);

        cout << a * b << endl;
    }

    return 0;
}
