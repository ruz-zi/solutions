/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <bits/stdc++.h>

using namespace std;

int Answer;

struct disjoint_set : vector<int> {
    disjoint_set(int _n) : vector<int>(_n, -1) {}

    int find(int u) {
        if (at(u) < 0) return u;
        return at(u) = find(at(u));
    }
    int uni(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return 0;
        if (at(u) > at(v)) std::swap(u, v);
        at(u) += at(v);
        at(v) = u;
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
		int n;
        cin >> n;
        disjoint_set ds(n);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (i + x < n && ds.uni(i, i + x))
                cnt++;
        }
        Answer = n - cnt;
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}