#include<bits/stdc++.h>

using namespace std;
int f[100];

int times;

list<int> li;

void dfs_visit(queue<int> *v,int u,int *c,int *pi){
    int p;
    c[u]=1;
    times=times+1;

    while(v[u].size()){
        p=v[u].front();
        v[u].pop();

        if(c[p]==0){
            pi[p]=u;
            dfs_visit(v,p,c,pi);
        }
    }

    f[u]=times=times+1;
    li.push_front(u);
}



void dfs(queue<int> *v,int *c,int *pi,int n){
    times=0;

    for(int i=1;i<=n;i++){
        if(c[i]==0){
             dfs_visit(v,i,c,pi);
        }
    }
}



int main(){

    int i,j,a,n,m,s,u,p,d, aux;


    while(cin >> n >> m){
        if(n == 0 && m == 0)break;
        queue<int> v[n+1];
        int c[n+1],pi[n+1];


        memset(c, 0 , sizeof(c));
        memset(pi, 0 , sizeof(pi));

        for(int i = 0 ; i < m ; ++i){
            cin >> aux >> a;
            v[aux].push(a);
        }

        dfs(v,c,pi,n);

        while(li.size()){
            cout<<li.front()<<" ";
            li.pop_front();
        }
        cout << endl;
    }

    return 0;
}
