#include <iostream>
#include <vector>

class Solution
{
public:
	Solution(int _n, int _k) : n(_n), k(_k)
	{
		values.resize(n);
		for (int i = 0; i < n; i++)
		{
			std::cin >> values[i];
		}

		dp.resize(k + 1);
		dp[0] = 1;
	}
	int solve()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = values[i]; j <= k; j++)
			{
					dp[j] += dp[j - values[i]];
			}
		}
		return dp[k];
	}
private:
	int n, k;
	std::vector<int> values, dp;
};
