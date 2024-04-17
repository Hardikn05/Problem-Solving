class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> ans(n,true);
        for(int i=0;i<edges.size();i++)
        {
            ans[edges[i][1]]=false;
        }
        vector<int> uttar;
        for(int i=0;i<n;i++)
        {
            if(ans[i])
            uttar.push_back(i);
        }
        return uttar;
    }
};
