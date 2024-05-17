class Solution {
public:
     int mod = (int)1e9 + 7;
    long long memoization(string& str, int idx, vector<long long>& dp) {
        int n = str.size();
        if (idx == n) {
            return dp[idx] = 1;
        }

        if (dp[idx] != -1)
            return dp[idx];

        char ch = str[idx];
        if (ch == '0')
            return dp[idx] = 0;

        long count = 0;
        if (ch == '*') {
            count += 9 * memoization(str, idx + 1, dp) % mod;
            if (idx < n - 1) {
                char ch1 = str[idx + 1];
                if (ch1 >= '0' && ch1 <= '6')
                    count += 2 * memoization(str, idx + 2, dp) % mod;
                else if (ch1 >= '7' && ch1 <= '9')
                    count += memoization(str, idx + 2, dp) % mod;
                else
                    count = (count + 15 * memoization(str, idx + 2, dp)) % mod; 
            }
        } else {
            count += 1 * memoization(str, idx + 1, dp) % mod;
            if (idx < n - 1) {
                char ch1 = str[idx + 1];
                if (ch1 == '*' && ch == '1')
                    count += 9 * memoization(str, idx + 2, dp) % mod;
                else if (ch1 == '*' && ch == '2')
                    count += 6 * memoization(str, idx + 2, dp) % mod;
                else if (ch1 != '*') {
                    int num = (ch - '0') * 10 + (ch1 - '0');
                    if (num <= 26)
                        count = (count + 1 * memoization(str, idx + 2, dp)) % mod;
                }
            }
        }

        return dp[idx] = count;
    }
    int numDecodings(string s) {
        vector<long long> dp(s.size()+1,-1);
        return memoization(s,0,dp);
    }
};
