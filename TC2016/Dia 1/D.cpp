#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

map<ll, bool> b;
vector<ll> v;


ll d[] = {2, 3, 5};

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const ll& lhs, const ll&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};

typedef std::priority_queue<ll,std::vector<ll>,mycomparison> mypq_type;

void bfs(){
    
	mypq_type q(mycomparison(true));
	q.push(1);
	
	while(!q.empty()){
		ll curr = q.top();
		q.pop();
		v.push_back(curr);
		
		if(v.size() == 1500)break;
		
		for(int i =  0 ; i < 3 ; ++i){
			if(b[curr * d[i]] == 0){
			    b[curr * d[i]] = 1;
				q.push(curr * d[i]);
			}
		}
	}
	sort(v.begin(), v.end());
}

int main(){
	bfs();
	int n;
	
	while(cin >> n){
		if(!n)break;
		cout << v[n-1] << "\n";
	}
	return 0;
}
