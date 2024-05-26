class Solution {
public:
    bool ispossible(vector<int>& heater,vector<int>& houses,int r)
    {
        int i=0,j=0;
        while(i<houses.size())
        {
            if(j==heater.size())return false;
            int hpos=heater[j++];
            int lpos=hpos-r;
            int rpos=hpos+r;
            while(i<houses.size()&&houses[i]>=lpos&&houses[i]<=rpos)
                i++;
        }
        return true;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n=houses.size();
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        long long low=0,high=INT_MAX;
        int ans;
        while(low<=high)
        {
            int m=low+(high-low)/2;
            if(ispossible(heaters,houses,m))
            {
                ans=m;
                high=m-1;
            }
            else
                low=m+1;
        }
        return ans;
    }
};
