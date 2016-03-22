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

#define TEST(t) int T; cin >> T; for(int t = 1 ; t <= T ; ++t)

using namespace std;

#define MAXS 101
#define MAX 10001

int memo[MAXS][MAX];
string dp[MAXS][MAX];

string s, st;
int tlen, slen;

string add(string s, string t){
	if(t.size() > s.size())swap(s, t);
	int sl = s.size(), x, tl = t.size();
	
	bool llev = false;
	
	forn(i, sl-tl)t = "0" + t;
	
	rforn(i, sl){
		x = (s[i]-'0') + (t[i]-'0') + (llev?1:0);
		if(x >= 10){
			x -= 10;
			llev = true;
		}
		else llev = false;
		s[i] = x + '0';
	}
	if(llev)s = "1" + s;
	
	return s;
}

string F(int i, int j){
	if(i >= tlen || j >= slen)return "0";
	
	if(memo[i][j] == 1)return dp[i][j];
	memo[i][j] = 1;
	
	string ans;
	
	ans = F(i, j+1);
	
	if(st[i] == s[j]){
		if(i == tlen-1)ans = add(ans, add("1", F(i+1, j+1)));
		else ans = add(ans, F(i+1, j+1));
	}
	
	return dp[i][j] = ans;
}

int main(){
	
	TEST(t){
		cin >> s;
		cin >> st;
		slen = s.size();
		tlen = st.size();
		mset(memo, 0);
		
		cout << F(0, 0) << endl;
	}
	
	return 0;
}



