#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const int m = 250000;
	int n, h, d[2][m + 1];
	cin >> n;
	memset(d, -1, sizeof d);
	for (int i = 0; i < n; ++i) {
		cin >> h;
		for (int j = 0; j <= m; ++j) {
			if (d[i & 1][j] > 0) {
				if (j + h <= m)
					d[i + 1 & 1][j + h] = max(d[i + 1 & 1][j + h], d[i & 1][j] + h);
				if (j - h >= 0)
					d[i + 1 & 1][j - h] = max(d[i + 1 & 1][j - h], d[i & 1][j]);
				else if (h - j <= m)
					d[i + 1 & 1][h - j] = max(d[i + 1 & 1][h - j], d[i & 1][j] + h - j);
				d[i + 1 & 1][j] = max(d[i + 1 & 1][j], d[i & 1][j]);
			}
		}
		if (h <= m) d[i + 1 & 1][h] = max(d[i + 1 & 1][h], h);
	}
	cout << d[n & 1][0];

	return 0;
}