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
		int n, t;
		cin >> n >> t;
		string a(n, -1), b;
		cin >> b;
		for (int i = 0; i < n; ++i) {
			if (b[i] == '0') {
				if (i >= t) a[i - t] = '0';
				if (i + t < n) a[i + t] = '0';
			}
		}
		for (int i = 0; i < n; ++i) {
			if (a[i] == -1) {
				if (i + t < n && b[i + t] == '1' && (i + t + t >= n || a[i + t + t] == '0'))
					a[i] = '1';
				else if (i >= t && b[i - t] == '1' && (i - t - t < 0 || a[i - t - t] == '0'))
					a[i] = '1';
				else a[i] = '0';
			}
		}
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << a << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}