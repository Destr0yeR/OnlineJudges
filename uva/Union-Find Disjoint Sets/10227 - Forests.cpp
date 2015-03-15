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

int tree[101][101];
int padre[101];
int total;
int P, T;

int Find(int x){
    if(x == padre[x])return x;
    return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
    int padreX = Find(x);
    int padreY = Find(y);
    if(padreX == padreY)return;
    padre[padreX] = padreY;
    total--;
}

void init(){
    for(int i = 0 ; i <= P ; ++i){
        padre[i] = i;
        for(int j = 0 ; j <= T ; ++j){
            tree[i][j] = 0;
        }
    }
}

bool diff(int x, int y){
    for(int i = 0 ; i <= T ; ++i){
        if(tree[x][i] != tree[y][i])return true;
    }
    return false;
}

int process(){
    for(int i = 1 ; i <= P ; ++i){
        for(int j = i+1 ; j<= P ; ++j){
            if(!diff(i,j))Union(i, j);
        }
    }
}

int main()
{
    int x, y, n, i;
    char s[20];
    //freopen("10227 in.txt","r",stdin);
    //freopen("10227 out.txt","w", stdout);
    gets(s);
    sscanf(s,"%d", &n);
    gets(s);
    REP(i, n){
        gets(s);
        sscanf(s,"%d%d", &P, &T);
        init();
        total = P;
        //fflush(stdin);
        while(gets(s) && sscanf(s,"%d%d", &x, &y) == 2){
            tree[x][y] = 1;
        }
        process();
        if(i != 0)cout<<endl;
        cout<<total<<endl;
    }
    return 0;
}
