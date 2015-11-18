#include<bits/stdc++.h>

using namespace std;

double f(int h, int m, int s){
	return h*1.0 + (m*1.0 / 60.0 ) + (s*1.0 / 3600.0);
}

struct t{
	int h, m, s;
	
	t(){}
	t(int _h, int _m, int _s){h = _h; m = _m ; s = _s;}
};

double diff(t a, t b){
	return (a.h - b.h)*1.0 + (1.0*(a.m - b.m))/60.0 + (1.0*(a.s - b.s))/3600.0;
}

int main(){
	string s;
	stringstream ss;
	int v, lv = 0;
	//cout << diff(t(0,15,1), t(0,0,1)) << endl;
	t lt(0,0,0), cu;
	char c;
	
	double df, acu = 0.0;
	
	while(getline(cin, s)){
		ss.clear();
		ss << s;
		ss >> cu.h >> c >>  cu.m >> c >> cu.s;
		
		if(ss >> v){
			df = diff(cu, lt);
			acu += df*lv;
			lt = cu;
			lv = v;
		}
		else{
			df = diff(cu, lt);
			
			cout << s << " ";
			
			printf("%.2f km\n", acu+lv*df);
		}
		
	}
	
	return 0;
}
