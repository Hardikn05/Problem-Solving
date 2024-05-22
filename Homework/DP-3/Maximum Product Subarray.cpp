class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int mul=1;
        for(int i=0;i<nums.size();i++)
        {
           mul=mul*nums[i];
           ans=max(ans,mul);
           if(mul==0) 
           mul=1;
        }
        mul=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            mul=mul*nums[i];
           ans=max(ans,mul);
           if(mul==0) 
           mul=1;
        }
        return ans;
    }
};
