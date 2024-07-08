#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Solution
{
public:
    int n, m;
    void solve(string &s, string &t, int i, int j, vector<vector<int>> &dp, int len, string str, set<string> &ans, vector<vector<vector<string>>> &dp2)
    {
        if (str.size() == len)
        {
            ans.insert(str);
            dp2[i][j][len] = str;
            return;
        }
        if (i >= n || j >= m)
            return;

        int l = str.size();

        if (dp2[i][j][l] != "-1")
        {
            str += dp2[i][j][l];
            return;
        }
        if (s[i] == t[j])
        {
            str += s[i];
            int l = str.size();
            dp2[i][j][l] = str;
            solve(s, t, i + 1, j + 1, dp, len, str, ans, dp2);
        }
        else
        {
            if (dp[i][j + 1] == dp[i][j])
            {
                solve(s, t, i, j + 1, dp, len, str, ans, dp2);
            }
            if (dp[i + 1][j] == dp[i][j])
            {
                solve(s, t, i + 1, j, dp, len, str, ans, dp2);
            }
        }
    }
    vector<string> all_longest_common_subsequences(string s, string t)
    {
        n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (s[i] == t[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        int len = dp[0][0];
        set<string> ans;
        vector<vector<vector<string>>> dp2(n + 1, vector<vector<string>>(m + 1, vector<string>(len + 1, "-1")));
        solve(s, t, 0, 0, dp, len, "", ans, dp2);
        return vector<string>(ans.begin(), ans.end());
    }
};

int main()
{
    Solution obj;
    string S1 = "baabaca", S2 = "abaaa";

    auto start = high_resolution_clock::now();
    vector<string> result = obj.all_longest_common_subsequences(S1, S2);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Longest Common Subsequences are: " << endl;
    for (auto &it : result)
    {
        cout << it << endl;
    }
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;

    return 0;
}
