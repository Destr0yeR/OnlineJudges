#include <bits/stdc++.h>

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)

#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define forr(i, a, b) for(int i = a ; i < b ; ++i)

#define rforn(i, n) for(int i = n-1 ; i >= 0 ; --i)
#define rforr(i, a, b) for(int i = b-1 ; i >= a ; --i)

#define mset(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()

#define sz(x) (int)x.size()

#define TEST(t) int T; cin >> T; for(int t = 1 ; t <= T ; ++t)

using namespace std;

queue<vector<string> > que;
map<string, int > mp;
map<int, set<string> > rmp;
map<int, set<string> >::reverse_iterator it;
set<string>::iterator sit;

vector<string> m, today;

int main(){
    string s, st;
    int n;
    
    while((cin >> s)){
        if(s=="<text>"){
            today.clear();
            while(1){
                cin >> s;
                if(s=="</text>")break;
                if(sz(s)>=4)today.push_back(s);
            }
            que.push(today);
            forn(i, sz(today)){
				st = today[i];
                rmp[mp[st]].erase(st);
                mp[st]++;
                rmp[mp[st]].insert(st);
            }

            if(sz(que)>7){
                m=que.front();
                que.pop();

                forn(i, sz(m)){
					st = m[i];
                    rmp[mp[st]].erase(st);
                    mp[st]--;
                    if(mp[st])rmp[mp[st]].insert(st);
                }
            }
        }
        else if(s=="<top"){
            si(n);
            cin >> s;

            cout << "<top " << n << ">\n";
            for(it = rmp.rbegin(); n > 0 && it != rmp.rend() ; ++it){
                n-= (it->second).size();
                for(sit = (it->second).begin(); sit != (it->second).end(); sit++)cout << *sit << " " << it->first << endl;
            }
            cout << "</top>\n";
        }
    }
    return 0;
}



