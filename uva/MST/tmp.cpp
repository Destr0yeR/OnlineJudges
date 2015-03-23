#include<bits/stdc++.h>

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

typedef long long int64;
typedef unsigned int uint;

using namespace std;

#define sensors_sz_MAX 2001
#define edges_sz_MAX 1999001

struct edge {
	int64 x, y, w;

	edge(int64 ax = 0, int64 ay = 0, int64 aw = 0)
		: x(ax), y(ay), w(aw)
	{}

	bool operator < (const edge & a) const {
		return w < a.w;
	}
};

/* ufds */
int parent[sensors_sz_MAX];
void init_set() {
	for (int i = 0; i < sensors_sz_MAX; ++i)
		parent[i] = i;
}
int find_set(int x) {
	return x == parent[x] ? x : parent[x] = find_set(parent[x]);
}
void union_set(int x, int y) {
	parent[find_set(x)] = parent[find_set(y)];
}

/* given SHOULD put in namespace */
int rt_num; /* receiver/transmitter number */
vector<pair<int64, int64> > sensors;
vector<edge> edges;

void gen_edges() {
	for (uint i = 0; i < sensors.size(); ++i) {
		for (uint j = i+1; j < sensors.size(); ++j) {
			edges.push_back(edge(i, j, SQR(sensors[i].first-sensors[j].first) + SQR(sensors[i].second-sensors[j].second)));
		}
	}
}

int64 solve() {
	gen_edges();

	sort(edges.begin(), edges.end());
	init_set();

	int64 power_level_sqr = 0;
	int count = sensors.size() - rt_num;
	for (vector<edge>::iterator it = edges.begin(); count > 0 && it != edges.end(); ++it) {
		if (find_set(it->x) == find_set(it->y))
			continue;

		--count;
		union_set(it->x, it->y);
		power_level_sqr = max(it->w, power_level_sqr);
	}

	int64 power_level = static_cast<int64>(sqrt(static_cast<double>(power_level_sqr)));
	return power_level + (power_level*power_level < power_level_sqr);
}

int main() {
    freopen("1216 - in.txt","r",stdin);
    freopen("1216 - out.txt", "w", stdout);
	int test_n, x, y;
	sensors.reserve(sensors_sz_MAX);

	cin >> test_n;
	while (test_n--) {
		/* prepare stage */
		edges.resize(0);
		sensors.resize(0);

		/* input */
		cin >> rt_num;
		while (true) {
			cin >> x;
			if (x == -1)
				break;
			cin >> y;

			sensors.push_back(make_pair(x, y));
		}

		/* solve & output */
		cout << solve() << endl;
	}

	return 0;
}
