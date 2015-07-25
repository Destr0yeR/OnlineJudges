#include<bits/stdc++.h>

using namespace std;

char tablero[201][201];
int visitado[201][201];
int usado[201];
int niveles;

bool check(int x, int y, int n);
void dfs(int x, int y, int n);
void visit(int x, int y, int n);
void init(int n);
char proccess(int n);

int main()
{
    cin.sync_with_stdio(false);
    int n;
    //freopen("260 - in.txt", "r", stdin);
    //freopen("260 - out.txt", "w", stdout);
    for(int tc = 1 ; ; ++tc){
        cin>>n;
        if(n == 0)break;
        init(n);
        printf("%d %c\n", tc, proccess(n));
    }
    return 0;
}


bool check(int x, int y, int n){
    if(x>=0 && x<n && y>=0 && y<n){
        if(!visitado[x][y]  && tablero[x][y] == 'w'){
            dfs(x, y, n);
            return true;
        }
    }
    return false;
}

void print(int n)
{
    cout<<"******"<<endl;
    cout<<"usado"<<endl;
    cout<<"====="<<endl;
    for(int i = 0 ; i < n ; ++i){
        cout<<usado[i]<<endl;
    }
    cout<<endl<<"visitado"<<endl;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            cout<<visitado[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"*******"<<endl;
}

void visit(int x, int y, int n){
    if(check(x, y, n)){
        if(!usado[y]){
            usado[y] = 1;
            niveles++;
        }
    }
}

void dfs(int x, int y, int n){
    visitado[x][y] = 1;
    int i, j;
    i = x-1, j = y-1;
    visit(i, j , n);
    i = x-1, j = y;
    visit(i, j , n);
    i = x  , j = y-1;
    visit(i, j , n);
    i = x  , j = y+1;
    visit(i, j , n);
    i = x+1, j = y;
    visit(i, j , n);
    i = x+1, j = y+1;
    visit(i, j , n);
}

char proccess(int n){
    bool encontrado = false;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            if(!visitado[i][j]){
                memset(usado, 0, sizeof(usado));
                niveles = 0;
                dfs(i, j, n);
                //print(n);
                //cout<<niveles<<endl;
                if(niveles == n){
                    encontrado = true;
                    break;
                }
            }
        }
        if(encontrado)break;
    }
    if(encontrado){
        return 'W';
    }
    else{
        return 'B';
    }
}

void init(int n){
    memset(tablero, 'x', sizeof(tablero));
    memset(visitado, 0, sizeof(visitado));
    char tmp;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            cin>>tmp;
            //cout<<tmp;
            tablero[i][j] = tmp;
        }
    }
    /*cout<<"x"<<endl;
    for(int i = 0 ; i < n; ++i){
        for(int j = 0 ; j < n ; ++j){
            cout<<tablero[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"y"<<endl;*/
}

