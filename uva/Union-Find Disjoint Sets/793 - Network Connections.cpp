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

int T,n;
char q;
int x, y;
int padre[100005];
string s;

int Find(int x){
    if(padre[x] == x)return x;
    return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
    padre[Find(x)] = padre[Find(y)];
}

int main()
{
    //freopen("793 in.txt","r",stdin);
    //freopen("793 out.txt","w",stdout);
    scanf("%d",&T);
    int j;
    REP(j,T){
        scanf("%d",&n);
        int i;
        REP(i,n+1){padre[i]=i;}
        int sa = 0,ua = 0;
        cin.ignore(255,'\n');
        while(true){
            if(!getline(cin,s) || s.empty())break;
            sscanf(s.c_str(),"%c %d %d",&q,&x,&y);
            if(q == 'c'){
                Union(x,y);
            }
            else{
                if(Find(x)==Find(y))sa++;
                else ua++;
            }
        }
        printf("%d,%d\n",sa,ua);
        if(j!=T-1)printf("\n");
    }
    return 0;
}
