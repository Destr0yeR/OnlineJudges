#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
using namespace std;

#define DEBUG
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back

using namespace std;

typedef unsigned long long ull;


int main()
{
    int n;
    double w, rpta;
    cin >> n >> w;

    int total = 2*n;

    int cups[total];

    for(int i = 0 ; i < total ; ++i){
        cin >> cups[i] ;
    }

    sort(cups, cups + total);

    rpta = min(w, min(cups[0]*3.0*n, cups[n]*1.5*n));

    cout << setprecision(7) << rpta <<endl;

    return 0;
}
