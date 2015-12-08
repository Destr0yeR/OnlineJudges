#include <bits/stdc++.h>

using namespace std;

#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;

int K;
ll S;
set <ll> s;
vector <ll> v;

ll a[20000];
vector <ll> ans;

void generate(){
    int i;
    
    if(K > 10000) K = 10000;
    a[K-1] = a[K] = 1;
    for(i=K+1;;i++){
        a[i] = 2 * a[i-1] - a[i-1-K];
        if(a[i] > S) break;
    }
    
    for(int j = 0 ; j < i ; ++j) s.insert(a[j]);
    foreach(s,itr) v.push_back(*itr);
}

int main(void){
	
    cin >> S >> K;
    generate();
    
    int sz = v.size() - 1, i;
    
    while(S > 0){
        for(i= sz ; ;i--) if(v[i] <= S) break;
        S -= v[i];
        ans.push_back(v[i]);
    }
    
    while(ans.size() < 2) ans.push_back(0);
    
    sz = ans.size();
    
    cout << sz << endl;
    for(int i = 0 ; i < sz ; ++i){
		if(i)cout << " ";
        cout << ans[i];
    }
    cout << "\n";
    
    return 0;
}
