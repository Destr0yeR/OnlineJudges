#include<bits/stdc++.h>

using namespace std;

char board[9][9];
int c[9][9];

int dx[] = { 0, 0,-1, 1};
int dy[] = {-1, 1, 0, 0};

bool isValid(int x, int y){
    if(x < 0 || x >= 9)return false;
    if(y < 0 || y >= 9)return false;
    return true;
}

void dfs_erase(int x, int y){
    c[x][y] = 1;
    board[x][y] = '/';
    int pX, pY;
    for(int i = 0 ; i < 4 ; ++i){
        pX = x + dx[i];
        pY = y + dy[i];
        if(isValid(pX, pY)){
            if(c[pX][pY] == 0){
                if(board[pX][pY] == '-'){
                    dfs_erase(pX, pY);
                }
            }
        }
    }
}

void dfs_O(int x, int y){
    c[x][y] = 1;
    if(board[x][y] == '.'){
        board[x][y] = '+';
    }
    int pX, pY;
    char ch;
    for(int i = 0 ; i < 4 ; ++i){
        pX = x + dx[i];
        pY = y + dy[i];
        if(isValid(pX, pY)){
            ch = board[pX][pY];
            if(c[pX][pY] == 0){
                if(ch == 'O' || ch == '.' || ch == '+'){
                    dfs_O(pX, pY);
                }
                else if(ch == '-'){
                    dfs_erase(pX, pY);
                }
            }
        }
    }
}

void dfs_X(int x, int y){
    c[x][y] = 1;
    if(board[x][y] == '.'){
        board[x][y] = '-';
    }
    int pX, pY;
    char ch;
    for(int i = 0 ; i < 4 ; ++i){
        pX = x + dx[i];
        pY = y + dy[i];
        if(isValid(pX, pY)){
            ch = board[pX][pY];
            if(c[pX][pY] == 0){
                if(ch == 'X' || ch == '.' || ch == '-'){
                    dfs_X(pX, pY);
                }
            }
        }
    }
}

void dfs(){
    memset(c, 0, sizeof(c));
    for(int i = 0 ; i < 9 ; ++i){
        for(int j = 0 ; j < 9 ; ++j){
            if(c[i][j] == 0){
                if(board[i][j] == 'X')dfs_X(i, j);
            }
        }
    }

    memset(c, 0, sizeof(c));
    for(int i = 0 ; i < 9 ; ++i){
        for(int j = 0 ; j < 9 ; ++j){
            if(c[i][j] == 0){
                if(board[i][j] == 'O')dfs_O(i, j);
            }
        }
    }

    int b = 0;
    int w = 0;
    char ca;

    for(int i = 0 ; i < 9 ; ++i){
        for(int j = 0 ; j < 9 ; ++j){
            ca = board[i][j];
            if(ca == 'X' || ca == '-')b++;
            else if(ca == 'O' || ca == '+')w++;
        }
    }

    cout << "Black " << b << " White " << w << endl;
}

int main()
{
    //freopen(" - in.txt", "r", stdin);
    //freopen(" - out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int T;

    cin >> T;

    while(T--){
        for(int i = 0 ; i < 9 ;  ++i){
            for(int j = 0 ; j < 9 ; ++j){
                cin >> board[i][j];
            }
        }
        dfs();
    }

    return 0;
}
