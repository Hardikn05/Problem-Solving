class Solution {
public:
    int maxScore(vector<int>& ar, int k) {
         int sum =0,ans = INT_MIN;

         for(int i=0;i<k;i++)
         {
             sum+=ar[i];
         }
         ans=max(ans,sum);
         for(int i=0;i<k;i++)
         {
             sum+=ar[ar.size()-i-1];
             sum-=ar[k-i-1];

             ans=max(ans,sum);
         }

         return ans;
    }
};
