#include<bits/stdc++.h>

using namespace std;

int padre[501];

struct Key{
    int w, x, y, z;
}keys[501];

int distancia(Key a, Key b){
    int w = abs(a.w - b.w);
    if(w>5)w = 10-w;
    int x = abs(a.x - b.x);
    if(x>5)x = 10-x;
    int y = abs(a.y - b.y);
    if(y>5)y = 10-y;
    int z = abs(a.z - b.z);
    if(z>5)z = 10-z;
    return (w+x+y+z);
}

int Find(int x){
    if(x == padre[x]) return x;
    return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
    padre[Find(x)] = Find(y);
}

struct Edge{
    int x, y, d;
}arista[250001];

bool cmp(Edge a, Edge b){
    return a.d < b.d;
}

void assignKey(string key, int i)
{
    keys[i].w = key[0] - '0';
    keys[i].x = key[1] - '0';
    keys[i].y = key[2] - '0';
    keys[i].z = key[3] - '0';
}

bool init(int x){
    for(int i = 0 ; i <= x ; ++i)padre[i] = i;
}

int main()
{
    //freopen("1235 - in.txt","r",stdin);
    //freopen("1235 - out.txt","w",stdout);
    int T, n, cont, total, x, y, d, mini;
    string key;
    cin>>T;
    assignKey("0000", 0);

    for(int tc = 1 ; tc <= T ; ++tc){
        cin>>n;
        for(int i = 1 ; i <= n ; ++i){
            cin>>key;
            assignKey(key, i);
        }
        init(n);
        cont = 0;
        mini = 2147483647;
        for(int i = 1 ; i <= n ; ++i){
            d = distancia(keys[0], keys[i]);
            if(mini > d){
                mini = d;
                y = i;
            }
        }
        total = 0;
        Union(0, y);
        //cout<<keys[y].w<<keys[y].x<<keys[y].y<<keys[y].z<<endl;
        total += mini;
        //cout<<mini<<endl;
        for(int i = 1 ; i <= n ; ++i){
            for(int j = i+1 ; j <= n ; ++j){
                arista[cont].x = i;
                arista[cont].y = j;
                arista[cont].d = distancia(keys[i], keys[j]);
                cont++;
            }
        }

        sort(arista, arista + cont, cmp);

        /*for(int i = 0 ; i < cont ;++i){
            cout<<"arista: "<<i<<arista[i].x<<" "<<arista[i].y<<" "<<arista[i].d<<endl;
        }*/
        //cout<<"total: "<<total<<endl;
        for(int i = 0 ; i <cont ; ++i){
            x = arista[i].x;
            y = arista[i].y;
            d = arista[i].d;
            if(Find(x) != Find(y)){
                Union(x, y);
                total += d;
                //cout<<"total: "<<total<<endl;
                //cout<<"d: "<<d<<endl;
            }
        }
        printf("%d\n", total);
    }
    return 0;
}
