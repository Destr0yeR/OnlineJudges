#include<bits/stdc++.h>

using namespace std;

int h, w;


struct language{
    char let;
    int tot;
};

language lan[27];


bool cmp(language a, language b){
    if(a.tot == b.tot)return a.let < b.let;
    return a.tot > b.tot;
}

int c[1001][1001];
char mat[1001][1001];

int dh[] = { 0, 0,-1, 1};
int dw[] = {-1, 1, 0, 0};

bool isValid(int i, int j){
    if(i<0 || i >= h)return false;
    if(j<0 || j >= w)return false;
    return true;
}

void dfs_visit(int x, int y, char ch){
    c[x][y] = 1;
    int dx, dy;

    for(int i = 0 ; i < 4 ; ++i){
        dx = x + dh[i];
        dy = y + dw[i];

        if(isValid(dx, dy)){
            if(c[dx][dy] == 0 && mat[dx][dy] == ch)dfs_visit(dx, dy, ch);
        }
    }
}

void dfs(){
    char ch;
    for(int i = 0 ; i < h ; ++i){
        for(int j = 0 ; j < w ; ++j){
            if(c[i][j] == 0){
                ch = mat[i][j];
                lan[ch - 'a'].tot++;
                dfs_visit(i, j, ch);
            }
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

    cin >> T;

    for(int tc = 1 ; tc <= T ; ++tc){
        cin >> h >> w;
        memset(c, 0, sizeof(c));
        for(int i = 0 ; i < 27 ; ++i){
            lan[i].let = i + 'a';
            lan[i].tot = 0;
        }

        for(int i = 0 ; i < h ; ++i){
            for(int j = 0 ; j < w ; ++j){
                cin >> mat[i][j];
            }
        }
        cout << "World #" << tc << endl;
        dfs();
        sort(lan, lan + 27 , cmp);

        for(int i = 0 ; i < 27 && lan[i].tot != 0; ++i){
            cout << lan[i].let << ": " << lan[i].tot << endl;
        }
    }

    return 0;
}
