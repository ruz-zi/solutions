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
		
		int n, m, k;
		cin >> n >> m >> k;
		
		vector<vector<int>> g(n + 1);
		int d[505][505];
		memset(d, 0, sizeof d);
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			d[u][v] = 1;
		}
		string ans(k, '0');
		vector<int> vis(n + 1);
		function<int(int, int)> connect = [&](int u, int to)
		{
			if (d[u][to]) return 1;
			vis[u] = 1;
			for (int v : g[u]) {
				if (!vis[v] && connect(v, to)) {
					d[u][to] = 1;
				}
			}
			return d[u][to];
		};
		for (int i = 0; i < k; ++i) {
			int u, v;
			cin >> u >> v;
			vis = vector<int>(n + 1);
			if (connect(v, u)) {
				g[v].push_back(u);
				d[v][u] = 1;
				ans[i] = '1';
			}
			else {
				g[u].push_back(v);
				d[u][v] = 1;
			}
		}
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << ans << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}