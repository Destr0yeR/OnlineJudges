#include<bits/stdc++.h>

using namespace std;

char tablero[101][101];
int visitado[101][101];

int posiX[8]= {-1,-1,-1,0,0,1,1,1};
int posiY[8]= {-1,0,1,-1,1,-1,0,1};

void dfs(int i, int j){
    int vx,vy,k;
    tablero[i][j]='#';
    for(k=0; k<8; k++)
    {
        vx=i+posiX[k];
        vy=j+posiY[k];
        if(tablero[vx][vy]==' ')
        {
            dfs(vx,vy);
        }
    }
}

int main()
{
    //freopen(" - in.txt", "r", stdin);
    //freopen(" - out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    getchar();
    for(int tc = 1 ; tc <= T ; ++tc){
        //memset(tablero, 'x', sizeof(tablero));
        int cont = -1;
        while(gets(tablero[++cont])){
            if(tablero[cont][0] == '_')break;
        }
        bool encontrado = false;
        for(int i = 0 ; i < cont ; ++i){
            int x = strlen(tablero[i]);
            for(int j = 0 ; j < x ; ++j){
                if(tablero[i][j] == '*'){
                    dfs(i, j);
                    encontrado = true;
                }
                if(encontrado)break;
            }
            if(encontrado) break;
        }

        for(int i = 0 ; i <= cont ; ++i){
            cout<<tablero[i]<<endl;
        }
    }

    return 0;
}
