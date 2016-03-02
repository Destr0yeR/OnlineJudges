#include<bits/stdc++.h>

using namespace std;


int mat[501][501];

int v[501];
char f[501];

int main(){

    int n, m, s, d, sz, cont;

    bool pos = true;

    cin >> n >> m;

    memset(v, 0, sizeof(v));

    for(int i = 0 ; i < m ; ++i){
        cin >> s >> d;
        mat[s][d] = mat[d][s] = 1;
    }

    for(int i = 1 ; i <= n ; ++i){
        cont = 0;
        for(int j = 1 ; j <= n ; ++j){
            if(j == i)continue;
            if(mat[i][j] == 1)cont++;
        }
        if(cont == n-1){
            v[i] = 1;
            f[i] = 'b';
        }
    }

    char let[] = {'a', 'c'};
    int idx = 0;

    for(int i = 1 ; i <= n ; ++i){
        if(v[i] == 0){
            if(idx == 2){
                pos = false;
                break;
            }
            f[i] = let[idx];
            v[i] = 1;

            for(int j = 1 ; j <= n ; ++j){
                if(v[j] == 1)continue;
                if(mat[i][j] == 1){
                    f[j] = let[idx];
                    v[j] = 1;
                }
            }
            idx++;
        }
    }

    if(pos){
        for(int i = 1 ; i <= n ; ++i){
            switch(f[i]){
                case 'a':
                    for(int j = 1 ; j <= n ; ++j){
                        if(i == j)continue;
                        if(mat[i][j] == 1 && f[j] == 'c'){

                            pos = false;
                            break;
                        }
                        if(mat[i][j] == 0){
                            if(f[j] == 'a' || f[j] == 'b'){

                                pos = false;
                                break;
                            }
                        }
                    }
                    break;
                case 'c':
                    for(int j = 1 ; j <= n ; ++j){
                        if(i == j)continue;
                        if(mat[i][j] == 1 && f[j] == 'a'){

                            pos = false;
                            break;
                        }
                        if(mat[i][j] == 0){
                            if(f[j] == 'c' || f[j] == 'b'){
                                pos = false;
                                break;
                            }
                        }
                    }
                    break;
            }
        }
    }
    if(pos){
        cout << "Yes\n";
        for(int i = 1 ; i <= n ; ++i)cout << f[i];
        cout << "\n";
    }
    else cout << "No\n";

    return 0;
}
