#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int n, m;
    int mat[101][101];
    
    int row[101];
    int col[101];
    
    cin >> m >> n;
    
    memset(mat, 0, sizeof(mat));
    memset(row, 1, sizeof(row));
    memset(col, 1, sizeof(col));
    bool has_one = false;
    for(int i = 0 ; i < m ; ++i){
        for(int j = 0 ; j < n ; ++j){
            cin >> mat[i][j];
            if(mat[i][j])has_one = true;
        }
    }
    
    bool can_row = false;
    
    for(int i = 0 ; i < m ; ++i){
        if(mat[i][0]){
            for(int j = 0 ; j < n ; ++j){
                row[i] &= mat[i][j];
            }
        }
        else{
            row[i] = 0;
        }
        if(row[i])can_row = true;
    }
    
    bool can_col = false;
    for(int i = 0 ; i < n ; ++i){
        if(mat[0][i]){
            for(int j = 0 ; j < m ; ++j){
                col[i] &= mat[j][i];
            }
        }
        else{
            col[i] = 0;
        }
        if(col[i])can_col=true;
    }
    
    bool posible = true;
    
    for(int i = 0 ; i < m ; ++i){
        for(int j = 0 ; j < n ; ++j){
            if(mat[i][j]){
                if(!(row[i] || col[j]))posible = false;
            }
        }
    }
    if(!posible){
        cout << "NO" << endl;
        return 0;
    }
    
    if(!has_one){
        cout << "YES" << endl;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(j) cout << " ";
                cout << "0";
            }
            cout << endl;
        }
    }else if(can_col && can_row){
        cout << "YES" << endl;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(j) cout << " ";
                cout << (row[i]&&col[j])?"1":"0";
            }
            cout << endl;
        }
    }
    else{
        cout << "NO" << endl;
    }
    
    return 0;
}
