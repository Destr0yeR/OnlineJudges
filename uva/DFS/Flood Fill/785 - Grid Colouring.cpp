#include<bits/stdc++.h>

using namespace std;

int n, m;
char tablero[31][81];
int visitado[31][81];

int posiX[] = {-1, 0, 0, 1};
int posiY[] = { 0,-1, 1, 0};

void check(int x, int y, char color);
void dfs(int x, int y, char color);

int main()
{
    freopen("785 - in.txt", "r", stdin);
    freopen("785 - out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    bool usado = false, salto = false;
    int tmp = 0, state = 0;
    vector<int> v(0);
    n = -1;
    m =  0;
    v.clear();
    char color;
    memset(tablero, ' ', sizeof(tablero));
    memset(visitado, 0, sizeof(visitado));
    while(gets(tablero[++n]))
    {
        if(tablero[n][0]!='_'){
            int _tmp = strlen(tablero[n]);
            m = max(m, _tmp);
            if(tablero[n][0] == '\0'){
                if(!usado){
                    usado = true;
                    salto = true;
                }
                if(state != 1){
                    if(state !=0 )v.push_back(tmp);
                    state = 1;
                    tmp = 0;
                }
                tmp++;
                n--;
            }
            else{
                if(!usado){
                    usado = true;
                    salto = false;
                }
                if(state != 2){
                    if(state !=0 )v.push_back(tmp);
                    state = 2;
                    tmp = 0;
                }
                tmp++;
            }
        }
        if(tablero[n][0]=='_'){
            v.push_back(tmp);
            for(int i = 0 ; i < n ; ++i){
                for(int j = 0 ; j <= m ; ++j){
                    color = tablero[i][j];
                    if(!visitado[i][j] && (color != 'X' && color != ' ' && color != '_' && color != '\0')){
                        //printf("%d %d\n", i, j);
                        dfs(i, j, color);
                    }
                }
            }
            vector<int>::iterator it;
            int cont = 0;
            /*for(int i = 0 ; i <= n ; ++i){
                printf("%s\n", tablero[i]);
            }*/
            for(it = v.begin() ; it != v.end() ; ++it){
                if(salto){
                    for(int i = 0 ; i < *it ; ++i){
                        printf("\n");
                    }
                    salto = false;
                }
                else{
                    for(int i = 0 ; i < *it ; ++i){
                        printf("%s\n", tablero[cont++]);
                    }
                    salto = true;
                }
            }
            printf("%s\n", tablero[cont]);

            fflush(stdin);
            n = -1;
            m =  0;
            memset(tablero, ' ', sizeof(tablero));
            memset(visitado, 0, sizeof(visitado));
            usado = false;
            salto = false;
            tmp = 0;
            state = 0;
            v.clear();
        }
    }

    return 0;
}

void check(int x, int y, char color)
{
    if(x>=0 && x<n && y>=0 && y<=m){
        char _color = tablero[x][y];
        if(!visitado[x][y] && _color != 'X'){
            dfs(x, y, color);
        }
    }
}

void dfs(int x, int y, char color)
{
    visitado[x][y] = 1;
    tablero[x][y] = color;

    for(int i = 0 ; i < 4 ; ++i){
        check(x+posiX[i], y+posiY[i], color);
    }
}
