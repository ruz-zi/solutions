/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <bits/stdc++.h>

using namespace std;

int Answer;

long long a[606][606], col[606][606], ld[606][606], lu[606][606];
int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
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
		
		memset(a, 0, sizeof a);
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i <= n; ++i) {
			col[0][i] = ld[0][i] = lu[n + 1][i] = 0;
		}
		
		for (int i = 1; i <= n; ++i) {
			ld[i][0] = 0;
			for (int j = 1; j <= n; ++j) {
				col[i][j] = col[i - 1][j] + a[i][j];
				ld[i][j] = ld[i - 1][j - 1] + a[i][j];
			}
		}
		for (int i = n; i >= 1; --i) {
			lu[i + 1][0] = 0;
			for (int j = 1; j <= n; ++j) {
				lu[i][j] = lu[i + 1][j - 1] + a[i][j];
			}
		}
		auto colps = [&](int x, int l, int r) {
			if (x < 1 || x > n) return 0ll;
			if (l > n || r < 1) return 0ll;
			if (r > n) r = n;
			if (l < 1) l = 1;
			return col[r][x] - col[l - 1][x];
		};
		auto ldps = [&](int y, int x, int k) {
			if (x > n) y -= x - n, k -= x - n, x = n;
			if (y > n) x -= y - n, k -= y - n, y = n;
			if (x < 1 || y < 1) return 0ll; 
			if (k <= 0) return 0ll;
			if (x - k < 0) k = x;
			if (y - k < 0) k = y;
			return ld[y][x] - ld[y - k][x - k];
		};
		auto lups = [&](int y, int x, int k) {
			if (x > n) y += x - n, k -= x - n, x = n;
			if (y < 1) x -= 1 - y, k -= 1 - y, y = 1;
			if (y > n || x < 1) return 0ll;
			if (k <= 0) return 0ll;
			if (x - k < 0) k = x;
			if (y + k > n + 1) k = n - y + 1;
			return lu[y][x] - lu[y + k][x - k];
		};
		long long ans = 0, sum = 0, rtri = 0, ltri = 0;
		for (int i = 1 - n; i <= n + n; ++i) {
			sum = rtri = ltri = 0;
			for (int j = 1 - n; j <= n + n; ++j) {
				rtri += ldps(i, j + k - 1, k) + lups(i + 1, j + k - 2, k - 1) - colps(j - 1, i - k + 1, i + k - 1);
				sum += rtri;
				sum -= ltri;
				ltri += colps(j, i - k + 1, i + k - 1) - lups(i - k + 1, j - 1, k) - ldps(i + k - 1, j - 1, k - 1);
				ans = max(ans, sum);
			}
		}
		
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << ans << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}