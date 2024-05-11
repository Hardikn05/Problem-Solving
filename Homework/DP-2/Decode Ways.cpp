class Solution {
public:
    int Memoization(string s, int i ,vector<int>& dp)
    {
        if(i>=s.length())
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        int  curr=0;
        if(s[i]!='0')
        {
            curr += Memoization(s,i+1,dp);
        }
        if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6'))
        {
            curr += Memoization(s,i+2,dp);
        }
        return dp[i]=curr;
    }
    int tabulation(string s)
    {
        int n = s.size();
   	    vector<int> dp(n + 1, 0);
   	    dp[0] = 1;
        if(s[0]!='0')
        dp[1] = 1;
        else
        dp[1] = 0;

   	    for (int index = 2; index <= n; index++)
   	    {
   	        if (s[index - 1] != '0')
   	            dp[index] += dp[index - 1];

   	        int num = stoi(s.substr(index - 2, 2));
   	        if (num >= 10 && num <= 26)
   	            dp[index] += dp[index - 2];
   	    }

   	    return dp[n];
    }

    int numDecodings(string s) {
        // int i = s.length();
        // vector<int>dp(i+1,-1);
        // return Memoization(s,0,dp);
        return tabulation(s);
    }
};
