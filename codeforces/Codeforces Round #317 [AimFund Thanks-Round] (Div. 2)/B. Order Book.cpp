#include<bits/stdc++.h>

#define mset(x,y) memset(x, y, sizeof(x))

using namespace std;

map<int, int> s;
map<int, int> b;

vector<int> vs;
vector<int> vb;

bool cmp(int a, int _b){
	return a < _b;
}

bool cmp2(int a, int _b){
	return a > _b;
}

int main(){
	
	int n, m, x, y;
	char c;
	
	cin >> n >> m;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> c >> x >> y;
		if(c == 'S'){
			if(s[x]==0){
				vs.push_back(x);
			}
			s[x]+=y;
		}
		else {
			if(b[x]==0){
				vb.push_back(x);
			}
			b[x]+=y;
		}
	}
	
	sort(vs.begin(), vs.end(), cmp);
	sort(vb.begin(), vb.end(), cmp2);
	
	int cont = 1;
	vector<int> rvs;
	vector<int>::iterator it;
	vector<int>::reverse_iterator rit;
	for(it = vs.begin() ; it != vs.end() ; ++it){
		if(cont > m)break;
		rvs.push_back(*it);
		cont++;
	}
	
	for(rit = rvs.rbegin() ; rit != rvs.rend() ; ++rit){
		cout << "S " << *rit << " " << s[*rit] << endl;
	}
	cont = 1;
	for(it = vb.begin() ; it != vb.end() ; ++it){
		if(cont > m)break;
		cout << "B " << *it << " " << b[*it] << endl;
		cont++;
	}

	return 0;
}
