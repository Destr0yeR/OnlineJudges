#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 2000;
const int MAX_K = (int)(1e5);
const int INF = 1<<29;

int N, M, K;
bool filled[MAX_N][MAX_N];
int low[MAX_N][MAX_N], high[MAX_N][MAX_N];
int xs[MAX_K], ys[MAX_K];

void init() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < K; ++i) {
		scanf("%d%d", xs+i, ys+i);
		--xs[i];
		--ys[i];
	}
}

void proc(int x, int y) {
	int mini = INF;
	for (int xx = max(0, x-10); xx < min(N, x+10); ++xx) {
		mini = min( mini, abs(xx - x) + abs(y - low[xx][y]) );
		mini = min( mini, abs(xx - x) + abs(y - high[xx][y]) );
	}
	++mini;
	int bx = -1, by = -1;
	for (int xx = max(0, x - mini); xx < N && x + mini >= xx; ++xx) {
		int d = abs(xx - x) + abs(y - low[xx][y]);
		if (d < mini) {
			mini = d;
			bx = xx;
			by = low[xx][y];
		}
		d = abs(xx - x) + abs(y - high[xx][y]);
		if (d < mini) {
			mini = d;
			bx = xx;
			by = high[xx][y];
		}
	}

	printf("%d %d\n", bx + 1, by + 1);
	filled[bx][by] = true;
	int l = (by == 0 ? -INF : low[bx][by-1]), h = (by == M - 1 ? +INF : high[bx][by+1]);
	for (int yy = by; yy < M && l < by; ++yy) {
		if (!filled[bx][yy]) {
			l = yy;
		}
		low[bx][yy] = l;
	}
	for (int yy = by ; yy >= 0 && h > by; --yy) {
		if (!filled[bx][yy]) {
			h = yy;
		}
		high[bx][yy] = h;
	}

}

void solve() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			low[i][j] = high[i][j] = j;
		}
	}
	for (int i = 0; i < K; ++i) {
		proc(xs[i], ys[i]);
	}
}

int main() {
	init();
	solve();

	return 0;
}
