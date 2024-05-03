class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int temp1 = nums[0];

        if(n==1)
        return temp1;

        int temp2 = nums[1];
        if(n==2)
        return max(temp2,temp1);

        int temp3 = (nums[2]+temp1);
        if(n==3)
        return max(temp3,temp2);

        for(int i=3;i<n;i++)
        {
            int ans = nums[i]+max(temp1,temp2);
            temp1 = temp2;
            temp2 = temp3;
            temp3 = ans;
        }
        return max(temp3,temp2);
    }
};
