#include<bits/stdc++.h>

using namespace std;

int tablero[26][26];
int visitado[26][26];

int posiX[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int posiY[] = {-1, 0, 1,-1, 1,-1, 0, 1};

int n;

void init();
int process();
void dfs(int x, int y);
void check(int x, int y);

int main()
{
    cin.sync_with_stdio(false);
    //freopen("352 - in.txt", "r", stdin);
    //freopen("352 - out.txt", "w", stdout);
    int tc = 1;
    while(cin>>n){
        init();
        printf("Image number %d contains %d war eagles.\n", tc++, process());
        fflush(stdin);
    }
    return 0;
}

void init(){
    char tmp;
    memset(visitado, 0, sizeof(visitado));
    //cout<<n<<endl;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            cin>>tmp;
            //cout<<endl<<i*n + j+1<<endl;
            tablero[i][j] = tmp - '0';
        }
    }
    //cout<<n<<endl;
}
void check(int x, int y){
    if(x >=0 && x < n && y >= 0 && y < n){
        if(!visitado[x][y] && tablero[x][y] == 1){
            dfs(x, y);
        }
    }
}

void dfs(int x, int y){
    visitado[x][y] = 1;
    for(int i = 0 ; i < 8 ; ++i)check(x+posiX[i], y+posiY[i]);
}

int process(){
    //cout<<"@@"<<endl;
    int total = 0;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            if(!visitado[i][j] && tablero[i][j] == 1){
                dfs(i, j);
                total++;
            }
        }
    }
    //printf("total : %d\n", total);
    return total;
}
