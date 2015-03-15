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

int A, B;
bool setA, setB;

int aliado[10001];
int enemigo[10001];

int Find(int x){
    if(x == aliado[x])return x;
    return aliado[x] = Find(aliado[x]);
}

bool areFriends(int x, int y){
    if(x == -1 || y == -1)return false;
    int aliadoX = Find(x);
    int aliadoY = Find(y);

    return (aliadoX == aliadoY);
}

bool areEnemies(int x, int y){

}

bool setFriends(int x, int y){
    if(areEnemies(x, y))return false;
    if(areFriends(x, y))return true;

    int aliadoX = Find(x);
    int aliadoY = Find(y);

    int enemigoX = enemigo[aliadoX];
    int enemigoY = enemigo[aliadoY];

    aliado[aliadoX] = aliadoY;
    if(enemigoX == -1){
        if(enemigoY == -1){
            return true;
        }
        else{
            enemigo[aliadoX] = enemigoY;
        }
    }
    else{
        if(enemigoY == -1){
            enemigo[aliadoY] = enemigoX;
        }
        else{
            if(enemigoX == enemigoY){
                return true;
            }
            else{
                int aliadoEnemigoX = Find(enemigoX);
                int aliadoEnemigoY = Find(enemigoY);

                enemigo[aliadoX] = aliadoEnemigoY;
                enemigo[aliadoY] = aliadoEnemigoY;

                setFriends()
            }
        }
    }
    return true;
}

bool setEnemies(int x, int y){

}


int main()
{
    freopen("10158 in.txt","r",stdin);
    freopen("10158 out.txt","w",stdout);
    int n, c, x, y, i;
    scanf("%d",&n);
    REP(i,n+1){aliado[i]=i;enemigo[i]=-1;}
    while(scanf("%d %d %d", &c, &x, &y)){
        if(c == 0 && x == 0 && y == 0)break;
        switch(c){
            case 1:
                if(!setFriends(x, y))printf("-1\n");
                break;
            case 2:
                if(!setEnemies(x, y))printf("-1\n");
                break;
            case 3:
                printf("%d\n",(areFriends(x, y)?1:0));
                break;
            case 4:
                printf("%d\n",(areEnemies(x, y)?1:0));
                break;
        }
    }

    return 0;
}
