#include<bits/stdc++.h>

using namespace std;

char tablero[101][101];
int visitado[101][101];
int cantidad[101][101];

int posiX[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int posiY[] = {-1, 0, 1,-1, 1,-1, 0, 1};

int n, m;

vector<int> pX(0);
vector<int> pY(0);

void init(){
    memset(visitado, 0, sizeof(visitado));
    memset(cantidad, 0, sizeof(cantidad));
}

void check(int x, int y);
void dfs(int x, int y);

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    //freopen("469 - in.txt", "r", stdin);
    //freopen("469 - out.txt", "w", stdout);
    int T, c, r;
    string line;
    scanf("%d", &T);
    getchar();
    gets(tablero[0]);
    for(int tc = 1 ; tc <= T ; ++tc){
        n = -1;
        while(gets(tablero[++n])){
            if(tablero[n][0] != 'L' && tablero[n][0] != 'W')break;
        }
        n--;
        m = strlen(tablero[0]);
        init();
        for(int i = 0 ; i <= n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(!visitado[i][j] && tablero[i][j] == 'W'){
                    pX.clear();
                    pY.clear();
                    dfs(i, j);
                    for(int i = 0 ; i < pX.size() ; ++i){
                        cantidad[pX[i]][pY[i]] = pX.size();
                    }
                }
            }
        }
        if(tc != 1)cout<<endl;
        do{
            string tmp(tablero[n+1]);
            if(tmp.empty())break;

            sscanf(tablero[n+1], "%d %d", &c, &r);

            cout<<cantidad[c-1][r-1]<<endl;
        }
        while(gets(tablero[n+1]));
    }

    return 0;
}

void check(int x, int y){
    if(x >= 0 && x <= n && y >= 0 && y < m){
        if(!visitado[x][y] && tablero[x][y] == 'W'){
            dfs(x, y);
        }
    }
}

void dfs(int x, int y){
    visitado[x][y] = 1;
    pX.push_back(x);
    pY.push_back(y);
    for(int i = 0 ; i < 8 ; ++i){
        check(x+posiX[i], y+posiY[i]);
    }
}
