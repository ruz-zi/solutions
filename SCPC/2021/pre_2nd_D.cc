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

	
	const int mod = 1e9 + 7;
	auto mpow = [mod](long long a, long long e) {
		long long r = 1;
		while (e > 0) {
			if (e & 1) r = r * a % mod;
			a = a * a % mod;
			e >>= 1;
		}
		return r;
	};
	const int inv = mpow(3881, mod - 2);
	vector<long long> xi(2000001);
	xi[2000000] = 3881;
	for (int i = 1999999; i >= 0; --i)
		xi[i] = xi[i + 1] * 3881 % mod;
		
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
		
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		long long ans = 0;
		vector<vector<long long>> ab(s.size(), vector<long long>(26));
		for (int i = 0; i < s.size(); ++i) {
			ab[i][s[i] - 'a'] = (i ? ab[i - 1][s[i] - 'a'] : 0) + xi[i];
			ab[i][s[i] - 'a'] %= mod;
		}
		auto ps = [&](int l, int r) {
			vector<long long> res(26);
			for (int i = 0; i < 26; ++i) {
				res[i] = (ab[r][i] - (l ? ab[l - 1][i] : 0)) * mpow(mpow(3881, r - l + 1) % mod, mod - 2);
			}
			return res;
		};
		map<vector<long long>, int> mp[505];
		for (int len = 1; len <= 500; ++len) {
			for (int i = len; i < s.size(); ++i) {
				auto p = ps(i - len, i);
				mp[len][p]++;
			}
		}
		
		for (long long x = 1; x <= k; ++x) {
			string p;
			cin >> p;
			if (p.size() > s.size()) continue;
			vector<long long> a(26), b(26);
			for (int i = 0; i < p.size(); ++i) {
				a[p[i] - 'a'] += xi[i];
				a[p[i] - 'a'] %= mod;
			}
			ans += x * mp[p.size()][a];
		}
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << ans << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}