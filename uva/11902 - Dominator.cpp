#include<bits/stdc++h>

using namespace std;

int main(){
	int t;
	string w;
	cin >> t;
	while(t--) {
		int v = 0, c = 0;
		cin >> w;
		cout << w << endl;
		for(int i = 0; i < w.size(); ++i) {
			if(w[i] == 'a' or w[i] == 'e' or w[i] == 'i' or w[i] == 'o' or w[i] == 'u') ++v;
			else ++c;
		}
		cout << (v > c? 1 : 0) << endl;
	}
	return 0;
}
