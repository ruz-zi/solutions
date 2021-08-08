/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <bits/stdc++.h>

using namespace std;
int Answer;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		long long k;
		cin >> k;
		struct PT {long long x, y;} pt[8];
		for (int i = 0; i < 8; ++i) {
			cin >> pt[i].x >> pt[i].y;
		}
		long long dx[] = {0, 0, k, k, k*2, k*2, k*3, k*3};
		long long dy[] = {k, k*2, 0, k*3, 0, k*3, k, k*2};
		vector<vector<int>> adj(20);
		int n = 8, m = 8;
		long long ca[20][20]{}, co[20][20]{}, p[20]{}, d[20]{};
		for(int i=1; i<=n; ++i) {
			adj[0].push_back(i);
			adj[i].push_back(0);
		}
		for(int i =1; i<=m; ++i) {
			adj[i + n].push_back(n + m + 1);
			adj[n + m + 1].push_back(i + n);
		}
		for(int i =1; i<=m; ++i) {
			for(int j =1; j<=n; ++j) {
				adj[j].push_back(i + n);
				adj[i + n].push_back(j);
			}
		}
		auto f = [&](long long x, long long y) {
			long long a, ans = 0;
			memset(ca, 0, sizeof ca);
			memset(co, 0, sizeof co);
			for(int i=1; i<=n; ++i) {
				ca[0][i] = 1;
			}
			for(int i =1; i<=m; ++i) {
				ca[i + n][n + m + 1] = 1;
			}
			for(int i =1; i<=m; ++i) {
				for(int j =1; j<=n; ++j) {
					a = abs(x + dx[j - 1] - pt[i - 1].x) + abs(y + dy[j - 1] - pt[i - 1].y);
					ca[j][i + n] = INT_MAX;
					co[j][i + n] = a;
					co[i + n][j] = -a;
				}
			}
			while(1) {
				memset(p, -1, sizeof p);
				memset(d, 0x3f, sizeof d);
				queue<pair<int, long long>> q;
				q.push({0, 0});
				p[0] = d[0] = 0;
				while(q.size()) {
					auto [a, c] = q.front(); q.pop();
					if (d[a] < c) continue;
					for(int b : adj[a]) {
						if (ca[a][b] <= 0) continue;
						long long nd = c + co[a][b];
						if (d[b] > nd) {
							d[b] = nd;
							p[b] = a;
							q.push({b, nd});
						}
					}
				}
				if (p[n + m + 1] == -1) break;
				for(int i =n + m + 1; i; i = p[i]) {
					ca[p[i]][i]--;
					ca[i][p[i]]++;
				}
				ans += d[n + m + 1];
			}
			return ans;
		};
		long long ans = LONG_LONG_MAX;
		
		long long xl = -4e8, xr = 4e8;
		long long yl = -4e8, yr = 4e8;
		while (xl + 3 < xr || yl + 3 < yr) {
			long long xml = (xl + xl + xr) / 3;
			long long xmr = (xl + xr + xr) / 3;
			long long yml = (yl + yl + yr) / 3;
			long long ymr = (yl + yr + yr) / 3;
			
			long long s1 = f(xmr, ymr);
			long long s2 = f(xml, ymr);
			long long s3 = f(xml, yml);
			long long s4 = f(xmr, yml);
			long long mn = min({s1, s2, s3, s4});
			if (s1 == mn) yl = yml, xl = xml;
			else if (s2 == mn) yl = yml, xr = xmr;
			else if (s3 == mn) yr = ymr, xr = xmr;
			else if (s4 == mn) yr = ymr, xl = xml;
		}
		for (long long x = xl; x <= xr; ++x) {
			for (long long y = yl; y <= yr; ++y) {
				ans = min(ans, f(x, y));
			}
		}
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << ans << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}