class Solution {
public:
    int recursion(string word1,string word2,int i,int j)
    {
        if(i==word1.size() && j==word2.size())
        return 0;

        if(i==word1.size())
        return word2.size()-j;
        
        if(j==word2.size())
        return word1.size()-i;

        if(word1[i]==word2[j])
        return recursion(word1,word2,i+1,j+1);

        int op_insert = recursion(word1,word2,i,j+1);
        int op_delete = recursion(word1,word2,i+1,j);
        int op_update = recursion(word1,word2,i+1,j+1);

        return min({op_insert,op_delete,op_update})+1;
    }
    int memoization(string word1,string word2,int i,int j,vector<vector<int>> &dp)
    {
        if(i==word1.size() && j==word2.size())
        return 0;

        if(i==word1.size())
        return word2.size()-j;
        
        if(j==word2.size())
        return word1.size()-i;

        if(dp[i][j]!=-1)
        return dp[i][j];

        if(word1[i]==word2[j])
        return dp[i][j]=memoization(word1,word2,i+1,j+1,dp);

        int op_insert = memoization(word1,word2,i,j+1,dp);
        int op_delete = memoization(word1,word2,i+1,j,dp);
        int op_update = memoization(word1,word2,i+1,j+1,dp);

        return dp[i][j]=min({op_insert,op_delete,op_update})+1;
    }
    int tabulation(string word1,string word2)
    {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        
        for(int i = 0; i <= m; i++)
            dp[i][0] = i;
        for(int j = 0; j <= n; j++)
            dp[0][j] = j;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(word1[i] == word2[j])
                    dp[i +1][j + 1] = dp[i][j];
                else{
                    int op_insert = dp[i + 1][j];
                    int op_delete = dp[i][j + 1];
                    int op_replace = dp[i][j];
                    dp[i + 1][j + 1] = 1 + min({op_insert,op_delete, op_replace});
                }
            }
        }
        
        return dp[m][n];
    }
    int spaceOptimization(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    if (m > n)
        return spaceOptimization(word2, word1);

    vector<int> prevRow(n + 1);
    vector<int> currentRow(n + 1);

    for (int j = 0; j <= n; j++)
        prevRow[j] = j;

    for (int i = 1; i <= m; i++) {
        currentRow[0] = i;
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1])
                currentRow[j] = prevRow[j - 1];
            else
                currentRow[j] = 1 + min({prevRow[j], currentRow[j - 1], prevRow[j - 1]});
        }
        swap(prevRow, currentRow);
    }

    return prevRow[n];
}
    int minDistance(string word1, string word2) {
        // vector<vector<int>> dp(word1.size(),vector<int> (word2.size(),-1));
        // return memoization(word1,word2,0,0,dp);
        return spaceOptimization(word1,word2);
    }
};
