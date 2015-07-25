#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n, aux;
    cin >> n;
    vector<int> v;
    map<int, int> m;
    vector<int> s;
    for(int i = 0; i < n ; ++i){
        cin >> aux;
        if(!m[aux]){
            v.push_back(aux);
        }
        m[aux]++;
    }

    sort(v.begin(), v.end());

    int ante = 0;

    for(int i = 0 ; i < v.size() ; ++i){
        s.push_back(m[v[i]] + ante);
        ante = s[i];
    }

    int rpta = n;

    int i;
    int j;
    int siz = v.size();

    for(i = 0 ; i < siz ; ++i){
        for(j = i ; j < siz ; ++j){
            if(v[i]*2 >= v[j]){
                aux = n - (s[j] - s[i] + m[v[i]]);
                rpta = min(rpta, aux);
            }
        }
    }

    cout << rpta << endl;

    return 0;
}
