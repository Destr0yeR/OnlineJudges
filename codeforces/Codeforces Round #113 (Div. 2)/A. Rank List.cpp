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

typedef unsigned long long ull;

struct team{
    int s;
    int p;
};

bool cmp(team a, team b){
    if(a.s == b.s){
        return a.p < b.p;
    }
    return a.s > b.s;
}

int main()
{

    int n, k;

    int _s, _p;

    cin >> n >> k;

    team teams[n];

    for(int i = 0 ; i < n ; ++i){
        cin >> teams[i].s >> teams[i].p;
    }

    sort(teams, teams + n, cmp);

    _s = teams[k-1].s;
    _p = teams[k-1].p;

    int total = 1;

    for(int i = k ; i < n ; ++i){
        if(teams[i].s != _s || teams[i].p != _p)break;
        total++;
    }
    for(int i = k-2 ; i >= 0 ; --i){
        if(teams[i].s != _s || teams[i].p != _p)break;
        total++;
    }
    cout << total << endl;
    return 0;
}
