#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int N, M;
int padre[27];
int usado[27];
int temporal[27];
int matriz[27][27];

int Find(int x){
    if(x == padre[x]) return x;
    return padre[x] = Find(padre[x]);
}

void copiar(int v[], int w[]){
    for(int i = 0 ; i <= 26 ; ++i){v[i]=w[i];}
}

void init(){
    for(int i = 0 ; i <= 26 ; ++i){
        padre[i]=i;
        for(int j = 0 ; j <= 26 ; ++j){
            matriz[i][j] = 0;
        }
    }
    for(int i = 0 ; i <= 26 ; ++i)usado[i]=-1;
}

void Union(int x, int y){
    padre[Find(x)] = Find(y);
}

int check(int x){
    int total = 0;
    for(int i = 0; i <= 26 ; ++i){
        if(matriz[x][i] == 1){
            if(usado[i] == 1)total++;
        }
    }
    return total;
}

void print(int v[])
{
    for(int i = 0 ; i <= 26 ; ++i){
        printf("%d ",v[i]);
    }
    printf("\n");
}
int main()
{
    //freopen("10507 in.txt","r",stdin);
    //freopen("10507 out.txt","w",stdout);
    char s[20];
    char x, y;
    while(gets(s) && sscanf(s,"%d",&N)==1){
        init();
        gets(s);
        sscanf(s,"%d",&M);
        gets(s);
        int inicial = 3;
        for(int i = 0 ; i < inicial ; ++i){
            usado[s[i] - 'A'] = 1;
        }

        for(int i = 0 ; i < M ; ++i){
            gets(s);
            sscanf(s,"%c %c",&x, &y);
            int a = x - 'A', b = y - 'A';
            if(usado[a] == -1)usado[a] = 0;
            if(usado[b] == -1)usado[b] = 0;
            matriz[a][b] = 1;
            matriz[b][a] = 1;
        }
        copiar(temporal,usado);
        int cont;
        int luego = 0;
        int dias = 0;
        do{
            copiar(temporal,usado);
            cont = 0;
            for(int i = 0 ; i<=26 ; ++i){
                if(usado[i] == 0){
                    int cant = check(i);
                    if(cant >= 3){
                        temporal[i] = 1;
                        cont++;
                        luego++;
                    }
                }
            }
            //print(temporal);
            //print(usado);
            copiar(usado,temporal);
            if(cont){dias++;}
        }
        while(cont !=0  && (luego + inicial < N));
        //cout<<luego<<" "<<inicial<<endl;
        if((luego + inicial) == N){
            printf("WAKE UP IN, %d, YEARS\n",dias);
        }
        else{
            printf("THIS BRAIN NEVER WAKES UP\n");
        }
        gets(s);
    }

    return 0;
}
