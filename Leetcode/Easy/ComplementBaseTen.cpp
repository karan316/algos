#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int findComplement(int N)
	{
		if (N < 2)
			return !N;
		int k;
		int i = 0;
		//         increment k until it becomes just greater than N
		while ((k = pow(2, i++) - 1) < N)
			;
		return k - N;
	}
};
