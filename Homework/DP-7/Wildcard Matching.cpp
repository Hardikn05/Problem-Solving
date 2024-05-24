class Solution {
public:
     bool solve(string s, string p, int i, int j,vector<vector<int>> &dp) {

        if (i == s.size() && j == p.size())
            return true;
        if (i < s.size() && j == p.size())
            return false;

        if(dp[i][j]!=-1)
        return dp[i][j];

        if (i < s.size() && (s[i] == p[j] || p[j] == '?'))
            return dp[i][j]=solve(s, p, i + 1, j + 1,dp);
        if (p[j] == '*') {
            return dp[i][j]=solve(s, p, i, j + 1,dp) || (i < s.size() && solve(s, p, i + 1, j,dp));
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int> (p.size()+1,-1));
        return solve(s,p,0,0,dp);
    }
};
