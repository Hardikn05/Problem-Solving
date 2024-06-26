class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(str1[i]==str2[j])
                {
                    dp[i+1][j+1]=1+dp[i][j];
                }
                else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        int size = m+n-dp[m][n];
        cout<<size;
        string ans(size,'.');
        int i = m, j = n, k = size - 1;
        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                ans[k--] = str1[i-1];
                i--;
                j--;
            } else if(dp[i-1][j] > dp[i][j-1]) {
                ans[k--] = str1[i-1];
                i--;
            } else {
                ans[k--] = str2[j-1];
                j--;
            }
        }
        while(i > 0) {
            ans[k--] = str1[--i];
        }
        while(j > 0) {
            ans[k--] = str2[--j];
        }
        return ans;
    }
};
