/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <bits/stdc++.h>

using namespace std;

int Answer;

struct disjoint_set {
	vector<int> a, c;
	vector<long long> b;
	disjoint_set(int n) {
		a.assign(n, -1);
		b.assign(n, 0);
		c.assign(n, 0);
	}
	int find(int u) {
		return a[u] < 0 ? u : find(a[u]);
	}
	long long weight(int u) {
		return a[u] < 0 ? 0 : weight(a[u]) + b[u];
	}
	void diff(int u, int v) {
		int anc;
		if ((anc = find(u)) != find(v))
			cout << "NC\n";
		else if (c[anc])
			cout << "CF\n";
		else cout << weight(v) - weight(u) << '\n';
	}
	int merge(int u, int v, long long w) {
		w += weight(u) - weight(v);
		u = find(u);
		v = find(v);
		if (u == v) {
			if (w != 0) c[u] = 1;
			return 0;
		}
		if (a[u] > a[v]) swap(u, v), w = -w;
		a[u] += a[v];
		a[v] = u;
		b[v] = w;
		return 1;
	}
};
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		cout << "Case #" << test_case+1 << endl;

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		int n, q;
		cin >> n >> q;
		disjoint_set ds(n + 1);
		while (q--) {
			int a, b, c, d;
			cin >> a;
			if (a == 1) {
				cin >> b >> c >> d;
				ds.merge(b, c, d);
			} else {
				cin >> b >> c;
				ds.diff(b, c);
			}
		}
		// Print the answer to standard output(screen).
		cout.flush();
	}

	return 0;//Your program should return 0 on normal termination.
}