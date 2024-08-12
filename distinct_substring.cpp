#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Solution
{
public:
    int n, m;
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
        if (j == m)
            return 1;
        if (i >= n)
            return 0;
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = 0, one = 0, second = 0;
        if (s[i] == t[j])
        {
            one = solve(s, t, i + 1, j + 1, dp);
        }
        second = solve(s, t, i + 1, j, dp);
        dp[i][j] = one + second;
        return one + second;
    }
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][m] = 1;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                long long one = 0, sec = 0;
                if (s[i] == t[j])
                {
                    one = dp[i + 1][j + 1];
                }
                sec = dp[i + 1][j];
                dp[i][j] = sec + one;
                if (dp[i][j] > INT_MAX)
                {
                    dp[i][j] = INT_MAX;
                }
            }
        }
        return dp[0][0];
    }
};

int main()
{
    Solution obj;
    string S1 = "babgbag", S2 = "bag";

    auto start = high_resolution_clock::now();
    int result = obj.numDistinct(S1, S2);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "So the ans is: " << result<<endl;
   
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;

    return 0;
}
