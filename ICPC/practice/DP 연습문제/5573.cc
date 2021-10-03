#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k, w, y{}, x{};
	int d[1001][1001]{};
	cin >> n >> m >> k;
	d[0][0] = k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> w;
			if (!(d[i][j] & 1)) w ^= 1;
			if (i == y && j == x) w ? x++ : y++;
			if (w) {
				d[i + 1][j] += (d[i][j] >> 1);
				d[i][j + 1] += (d[i][j] >> 1) + (d[i][j] & 1);
			}
			else {
				d[i + 1][j] += (d[i][j] >> 1) + (d[i][j] & 1);
				d[i][j + 1] += (d[i][j] >> 1);
			}
		}
	}
	cout << y + 1 << ' ' << x + 1;

	return 0;
}