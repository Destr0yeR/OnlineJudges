#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

bool matriz[2001][2001];
int d[2001][2001];
int a[2001][2001];
int l[2001][2001];

int n, m, k;

int px[100001];
int py[100001];

bool marcar(int x, int y)
{

    if(matriz[x][y])return false;
    if(x<1)return false;
    if(x>n)return false;
    if(y<1)return false;
    if(y>m)return false;

    matriz[x][y] = true;
    return true;
}

void buscar(int &x, int &y)
{
    int maxi = max(x-1,n-x)+max(y-1,m-y);
    int i = d[x][y];
    int j;
    for( ; i <= maxi ; ++i){
        d[x][y] = i;

        if(l[x][y] == 1){
            j = i;
            if(a[x][y] != -1){j = a[x][y]; a[x][y] = -1;}
            for( ; j >= 0 ; j--){
                if(marcar(x-j,y-(i-j)))     {l[x][y] = 1; a[x][y] = j; x -= j; y -= (i-j);return;}
                else if(marcar(x-j,y+(i-j))){l[x][y] = 1; a[x][y] = j; x -= j; y += (i-j);return;}
                l[x][y] = 2;
                a[x][y] = -1;
            }
        }

        if(l[x][y] == 2){
            j = 0;
            if(a[x][y] != -1){j = a[x][y]; a[x][y] = -1;}
            for( ; j <= i ; j++){
                if(marcar(x+j,y-(i-j)))     {l[x][y] = 2; a[x][y] = j; x += j; y -= (i-j);return;}
                else if(marcar(x+j,y+(i-j))){l[x][y] = 2; a[x][y] = j; x += j; y += (i-j);return;}
                l[x][y] = 1;
                a[x][y] = -1;
            }
        }

    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d %d %d",&n,&m,&k);

    for(int i = 1 ; i<= n ; ++i){
        for(int j = 1; j<= m ; ++j){
            matriz[i][j] = false;
            d[i][j] = 0;
            a[i][j] = -1;
            l[i][j] = 1;
        }
    }
    for(int i = 1 ; i<= k ; ++i){

        scanf("%d %d",&px[i],&py[i]);
        buscar(px[i], py[i]);
        printf("%d %d\n",px[i],py[i]);

    }
    return 0;
}
