#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Solution
{
public:
    int n, m;
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (i == n - 1 and j == m - 1)
        {
            if (s[i] == t[j])
                return 1;
            else
                return 0;
        }

        if (i >= n)
            return 0;
        if (j >= m)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if (s[i] == t[j])
        {
            ans = 1 + f(i + 1, j + 1, s, t, dp);
        }
        else
        {
            ans = max(f(i + 1, j, s, t, dp), f(i, j + 1, s, t, dp));
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string s, string t)
    {
        n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int ans = 0;
                if (s[i] == t[j])
                {
                    ans = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    ans = max(dp[i + 1][j], dp[i][j + 1]);
                }
                dp[i][j] = ans;
            }
        }
       // for debbugin purpose
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
               cout<<dp[i][j]<<" ";
             }cout<<endl;
        }
        return dp[0][0];
    }
};
int main()
{
    Solution obj;
    string S2 = "abaaa", S1 = "baabaca";

    auto start = high_resolution_clock::now();
    int result = obj.longestCommonSubsequence(S1, S2);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Longest Common Subsequence length: " << result << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;

    return 0;
}
