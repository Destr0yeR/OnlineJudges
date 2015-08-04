#include<bits/stdc++.h>

#define mset(x,y) memset((x), y, sizeof( (x) ));

using namespace std;

int times;
list<int> li;
int f[201];

void dfs_visit(queue<int>* v, int u, int* c, int *p){
    int _p;
    c[u] = 1;
    times++;

    while(v[u].size()){
        _p = v[u].front();
        v[u].pop();

        if(c[_p] == 0){
            p[_p] = u;
            dfs_visit(v, _p, c, p);
        }
    }
    f[u] = ++times;
    li.push_front(u);
}

void dfs(queue<int>* v, int* c, int* p ,int n){
    times = 0;

    for(int i = 0 ; i < n; ++i){
        if(c[i] == 0){
            dfs_visit(v,i,c,p);
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n, _m;
    int c[201], p[201];

    string s, a, b;
    int tc = 1;

    while(cin >> n){
        queue<int> v[n + 1];
        map<string , int> m;
        vector<string> rm;

        mset(c,0);
        mset(p,0);

        for(int i = 0 ; i < n ; ++i){
            cin >> s;
            m[s] = i;rm.push_back(s);
        }

        cin >> _m;

        for(int i = 0 ; i < _m ; ++i){
            cin >> a >> b;
            v[m[a]].push(m[b]);
        }

        dfs(v, c, p, n);

        cout << "Case # " << tc++ << ": Dilbert should drink beverages in this order: ";

        while(li.size()){
            cout<<rm[li.front()];
            if(li.size() != 1) cout << " ";
            else cout << ".";
            li.pop_front();
        }
        cout << endl;

    }


    return 0;
}
