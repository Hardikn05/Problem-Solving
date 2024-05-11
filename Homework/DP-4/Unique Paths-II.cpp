class Solution {
public:
 int Memoization(int m,int n,set<pair<int,int>> &s,vector<vector<int>> &dp)
 {
     if (m == 0 && n ==0)
     return 1;

     if(s.find(make_pair(m,n))!=s.end())
     return 0;

     else if( m<0 || n<0)
     return 0;

     else
     {
         if(dp[m][n]!=-1)
         return dp[m][n];

         int left = Memoization(m-1,n,s,dp);
         int right = Memoization(m,n-1,s,dp);
     return dp[m][n]=left + right;
     }
 }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
         set<pair<int,int>> s;

         for(int i=0;i<Grid.size();i++)
         {
             for(int j=0;j<Grid[0].size();j++)
             {
                 if(Grid[i][j])
                 {
                     s.insert(make_pair(i,j));
                 }
             }
         }
         int m=Grid.size()-1,n=Grid[0].size()-1;

         if(s.find(make_pair(m,n))!=s.end() || s.find(make_pair(0,0))!=s.end())
         return 0;

         vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
         return Memoization(m,n,s,dp);
    }
};
