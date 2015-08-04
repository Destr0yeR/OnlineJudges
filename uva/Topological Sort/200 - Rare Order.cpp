#include<bits/stdc++.h>

using namespace std;

int f[27];
int used[27];
int times;

list<int> li;

int toNumber(char s){return s - 'A';}
char toString(int n){return n + 'A';}

void dfs_visit(queue<int> *v, int u, int* c, int* pi){
    int p;
    c[u] = 1;
    times++;

    while(v[u].size()){
        p = v[u].front();
        v[u].pop();

        if(c[p] == 0 && used[p]){
            pi[p] = u;
            dfs_visit(v, p, c, pi);
        }
    }
    f[u] = ++times;
    li.push_front(u);
}

void dfs(queue<int> *v, int* c, int *pi, int n){
    times = 0;
    for(int i = 0 ; i < n ; ++i){
        if(c[i] == 0 && used[i]){
            dfs_visit(v, i, c, pi);
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    vector<string> p;
    queue<int> v[27];
    int c[27];
    int pi[27];
    string s;

    memset(c, 0, sizeof(c));
    memset(pi, 0, sizeof(pi));
    memset(used, 0, sizeof(used));

    while(cin >> s){
        if(s[0] == '#')break;
        p.push_back(s);
    }

    int p_size = p.size();
    int mini;
    int a, b;

    for(int i = 0 ; i < p_size-1 ; ++i){
        mini = min(p[i].size(), p[i+1].size());
        for(int j = 0 ; j < mini ; ++j){
            a = toNumber(p[i][j]);
            b = toNumber(p[i+1][j]);

            if(a != b){
                v[a].push(b);
                used[a] = 1;
                used[b] = 1;
                break;
            }
        }
    }


    dfs(v,c,pi,26);

    while(li.size()){
        cout<<toString(li.front());
        li.pop_front();
    }
    cout << endl;

    return 0;
}
