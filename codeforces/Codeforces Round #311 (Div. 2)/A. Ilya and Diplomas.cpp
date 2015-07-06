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
    int min1, min2, min3;
    int max1, max2, max3;

    cin>>n;
    cin>>min1>>max1;
    cin>>min2>>max2;
    cin>>min3>>max3;

    int a, b, c;

    if((max1 + min2 + min3) >= n){
        a =  n - (min2 + min3);
        b = min2;
        c = min3;
    }
    else if((max1 + max2 + min3) >= n){
        a = max1;
        b = n - (max1 + min3);
        c = min3;
    }
    else{
        a = max1;
        b = max2;
        c = n - (max1 + max2);
    }

    cout << a << " " << b << " " << c << endl;

    return 0;
}
