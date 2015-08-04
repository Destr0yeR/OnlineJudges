#include<bits/stdc++.h>

using namespace std;

char toChar(int n){return n+'a';}
int toNumb(char c){return c-'a';}

queue<int> v[28];
bool used[28];
int f[28];
int times;

list<int> li;

void dfs_visit(queue<int> *v, int u, int* c, int* p){
    int _p;
    c[u] = 1;
    times++;

    while(v[u].size()){
        _p = v[u].front();
        v[u].pop();

        if(c[_p] == 0){
            p[_p] = u;
            dfs_visit(v,_p,c,p);
        }

    }
    f[u] = ++times;
    li.push_front(u);
}

void dfs(queue<int>* v, int* c, int* p, int n){
    times=0;

    for(int i=0;i<=n;i++){
        if(c[i]==0 && used[i]){
             dfs_visit(v,i,c,p);
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int c[28];
    int p[28];

    string var, con;

    while( getline(cin, var) && getline(cin, con)){
        int v_size = var.size();
        int c_size = con.size();

        memset(used, 0, sizeof(used));
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));
        memset(p, 0, sizeof(p));

        for(int i = 0 ; i < v_size ; ++i){
            if(var[i] != ' ')used[toNumb(var[i])] = 1;
        }
        int x = 1;
        char a;
        char b;
        for(int i = 0 ; i < c_size ; ++i){
            if(var[i] != ' '){
                if(x == 1){
                    a = con[i];
                    x = 2;
                }
                else if(x == 2){
                    b = con[i];
                    v[toNumb(a)].push(toNumb(b));
                    x = 1;
                }
            }
        }
        dfs(v, c, p, 27);

        while(li.size()){
            cout<<toChar(li.front())<<" ";
            li.pop_front();
        }
        cout << endl;
    }
    return 0;
}
