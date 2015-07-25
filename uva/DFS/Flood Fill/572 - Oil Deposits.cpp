#include<bits/stdc++.h>

using namespace std;

char tablero[101][101];
int visitado[101][101];
int n, m;

int posiX[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int posiY[] = {-1, 0, 1,-1, 1,-1, 0, 1};

void init();
int process();
void dfs(int x, int y);

int main()
{
    //freopen("572 - in.txt", "r", stdin);
    //freopen("572 - out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    while(cin>>n>>m){
        if(n == 0 && m == 0)break;
        init();
        cout<<process()<<endl;
    }

    return 0;
}

void init(){
    memset(tablero, 'x', sizeof(tablero));
    memset(visitado, 0, sizeof(visitado));
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            cin>>tablero[i][j];
        }
    }
}

int process(){
    int total = 0;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            if(!visitado[i][j] &&tablero[i][j] == '@'){
                dfs(i, j);
                total++;
            }
        }
    }
    return total;
}

void check(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m){
        if(tablero[x][y] == '@' && !visitado[x][y])dfs(x,y);
    }
}

void dfs(int x, int y){
    visitado[x][y] = 1;
    for(int i = 0 ; i < 8 ; ++i){
        check(x+posiX[i], y+posiY[i]);
    }
}
