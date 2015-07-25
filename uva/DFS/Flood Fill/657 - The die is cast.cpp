#include<bits/stdc++.h>

using namespace std;

char tablero[51][51];
int visitado[51][51];

int w, h;

int dots;

int posiX[] = {-1, 0, 0, 1};
int posiY[] = { 0,-1, 1, 0};

void init();
vector<int> process();
void dfs(int x, int y, bool esX);
void check(int x, int y, bool esX);

int main()
{
    //freopen("657 - in.txt", "r", stdin);
    //freopen("657 - out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int tc = 1;
    while(cin>>w>>h){
        if(w == 0 && h == 0)break;
        init();
        printf("Throw %d\n", tc);
        vector<int> v = process();
        sort(v, v.size());
        int cont = 1;
        for(vector<int>::iterator it = v.begin() ; it != v.end() ; ++it){
            if(cont++ != 1)cout<<" ";
            cout<<(*it);
        }
        cout<<endl;
        cout<<endl;
    }

    return 0;
}


void check(int x, int y, bool fueX){
    if(x >= 0 && x < w && y >= 0 && y < h){
        if(!visitado[x][y] && tablero[x][y] != '.'){
            dfs(x, y, fueX);
        }
    }
}

void dfs(int x, int y, bool fueX){
    visitado[x][y] = 1;
    if(tablero[x][y] == 'X'){
        if(!fueX)dots++;
        fueX = true;
    }
    else{fueX = false;}

    for(int i = 0 ; i < 4 ; ++i){
        check(x+posiX[i], y+posiY[i], fueX);
    }
}

void init(){
    memset(tablero, '.', sizeof(tablero));
    memset(visitado, 0, sizeof(visitado));
    for(int i = 0 ; i < w ; ++i){
        for(int j = 0 ; j < h ; ++j){
            cin>>tablero[i][j];
        }
    }
}
vector<int> process(){
    vector<int> v(0);
    for(int i = 0 ; i < w ; ++i){
        for(int j = 0 ; j < h ; ++j){
            if(!visitado[i][j] && tablero[i][j] != '.'){
                bool esX = false;
                dots = 0;

                if(tablero[i][j] == 'X'){
                    esX = true;
                    dots = 1;
                }

                dfs(i, j, esX);
                v.push_back(dots);
            }
        }
    }
    cout<<endl;
}
