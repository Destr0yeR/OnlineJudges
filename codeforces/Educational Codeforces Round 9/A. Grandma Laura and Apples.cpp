#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, p, sz;
	ll ans = 0, tmp = 0;
	stack<int> st;
	
	string s;
	
	scanf("%d %d", &n, &p);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> s;
		sz = s.size();
		st.push(sz);
	}
	
	int curr;
	
	while(!st.empty()){
		curr = st.top();
		st.pop();
		
		if(curr == 4){
			ans = ans*2;
		}
		else{
			ans = ans*2+1;
			tmp++;
		}
	}
	
	ans =  ans*p - (tmp*p)/2;
	
	cout << ans << endl;
	
	
	return 0;
}
