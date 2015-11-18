#include <bits/stdc++.h>

using namespace std;

map<int, vector<int> >graph;
map<int, int> visitado;

void BFS(int x)
{
    queue<int> q;

    q.push(x);
    visitado[x] = 0;
    while(!q.empty())
    {
        int actual = q.front();
        q.pop();

        for(vector<int>::iterator it = graph[actual].begin() ; it!= graph[actual].end() ; ++it)
        {
            if(!visitado.count(*it))
            {
                visitado[*it] = visitado[actual]+1;
                q.push(*it);
            }
        }
    }
}

int main()
{
    int NC;
    int tc = 1;
    while(cin>>NC)
    {
        int a, b;
        if(NC == 0)break;

        int nodos = 0;


        for(int i = 0 ; i < NC ; ++i)
        {
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        while(cin>>a>>b)
        {
            if(a==0 && b== 0)break;
            visitado.clear();
            BFS(a);
            int total = 0;
            for(map<int, int>::iterator it = visitado.begin() ; it != visitado.end() ; ++it)
            {
                if(it->second > b)total++;
            }

            total += graph.size()-visitado.size();
            cout<<"Case "<<tc<<": "<<total<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<"."<<endl;
            tc++;
        }
        graph.clear();
    }

    return 0;
}
