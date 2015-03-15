#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

typedef unsigned long long ull;

int padre[27];
int matriz[27][27];

void remove_coma(char* s)
{
    char c = ',';
    char* end = s + strlen(s);
    end = remove(s, end, c);
    *end = '\0';
}

struct Edge{
    int x;
    int y;
    int d;
};

bool cmp(Edge a, Edge b){return a.d < b.d;}

vector<int> check(char s[], int n){
    int tmp = 0;
    int cont = 0;
    vector<int> v(0);
    for(int j = 0 ; j < strlen(s) ; ++j){
        if(s[j] >= '0' && s[j] <= '9'){
            tmp = tmp*10 + (s[j] - '0');
        }
        else{
            v.push_back(tmp);
            tmp = 0;
            cont++;
        }
    }
    if(cont!=n)v.push_back(tmp);

    return v;
}

int main()
{
    //freopen(" - in.txt","r",stdin);
    //freopen(" - out.txt","w",stdout);
    int T, c;
    char s[2000];
    int conex[27];
    gets(s);
    sscanf(s,"%d",&T);
    for(int tc = 1 ; tc <= T ; ++tc){
        gets(s);
        sscanf(s,"%d",&c);

        for(int i = 0 ; i < c ; ++i){padre[i] = i;}

        for(int i = 0 ; i < c ; ++i){
            gets(s);
            vector<int> tmp;
            remove_coma(s);
            tmp = check(s, c);
            for(int j = 0 ; j < tmp.size() ; ++j){
                matriz[i][j] = tmp[j];
            }
        }

        printf("Case %d:\n",tc);
    }


    return 0;
}
