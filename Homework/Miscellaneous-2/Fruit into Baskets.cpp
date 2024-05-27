class Solution {
public:
    int totalFruit(vector<int>& nums) {
        pair<int,int> first = {-1,-1},second = {-1,-1};
        int start = 0;
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==first.first)
            {
                first.second = i;
            }
            else if(nums[i]==second.first)
            {
                second.second = i;
            }
            else
            {
                if(first.second<=second.second)
                {
                start = first.second+1;
                first = second;
                second = make_pair(nums[i],i);
                }
                else
                {
                    start = second.second+1;
                    second = first;
                    first = make_pair(nums[i],i);
                }
            }
            ans = max(ans,i-start+1);
            cout<<ans<<endl;
        }
        return ans;
    }
};
