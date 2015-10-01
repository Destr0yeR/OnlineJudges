#include <bits/stdc++.h>

using namespace std;

struct time {
	int startTime;
	int endTime;
};

void solve (vector <struct time> t, int max);

int main()
{
	int T, N;
	cin >> T;
	struct time temp;
	vector <struct time> t;
	int max = 0;

	for (int i = 0; i < T; ++i) {
		cin >> N;
		for (int j = 0; j < N; ++j) {
			cin >> temp.startTime >> temp.endTime;
			t.push_back(temp);
			if (temp.endTime > max) max = temp.endTime;
		}
		solve(t, max);	
		t.clear();
	}
	return 0;
}

void solve (vector <struct time> t, int max)
{
	vector <int> s(max+1, 0);

	for (int k = 0; k < (int)t.size(); ++k) {
		for (int l = t[k].startTime; l <= t[k].endTime; ++l) {
			s[l]++;
		}
	}

	cout << *max_element(s.begin(), s.end()) << endl;		
}	
