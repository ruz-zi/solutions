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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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
		int n, m;
		cin >> n >> m;
		vector<int> bounds(4, INT_MIN), odd(4, INT_MIN);
		long long sum = 0, odd_cnt = 0, even = 0;
		auto update = [](vector<int>& a, int x, auto&& cmp) {
			if (cmp(a[0], x)) {
				a[3] = a[2];
				a[2] = a[1];
				a[1] = a[0];
				a[0] = x;
			} else if (cmp(a[1], x)) {
				a[3] = a[2];
				a[2] = a[1];
				a[1] = x;
			} else if (cmp(a[2], x)) {
				a[3] = a[2];
				a[2] = x;
			} else if (cmp(a[3], x)) {
				a[3] = x;
			}
		};
		for (int i = 0; i < n; ++i) {
			int y, x;
			cin >> y;
			vector<int> a(4, INT_MAX);
			for (int j = 0; j < y; ++j) {
				cin >> x;
				update(a, x, [](int a, int b){return a > b;});
			}
			sum += a[0] + a[1] + a[2] + a[3];
			if (y & 1) {
				odd_cnt++;
				sum += a[0];
				update(odd, a[2] + a[3], [](int a, int b){return a < b;});
			} else {
			    even += a[0] + a[1];
				update(bounds, a[2] + a[3], [](int a, int b){return a < b;});
			}
		}
		if (odd_cnt == 2 && n > 2) {
		    update(bounds, odd[0], [](int a, int b){return a < b;});
		    sum = min(sum - bounds[0] - bounds[1], sum - odd[0] - odd[1] + even);
		} else {
			update(bounds, odd[0], [](int a, int b){return a < b;});
			update(bounds, odd[1], [](int a, int b){return a < b;});
		    sum -= bounds[0] + bounds[1];
		}
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << sum << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}