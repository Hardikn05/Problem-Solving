class Solution {
public:
    vector<vector<int>> ans;
    void solve(TreeNode* r,int sum,vector<int>& t)
    {
        if(r==NULL)
          return;
        if(!r->left&&!r->right&&r->val==sum)
        {
            t.push_back(r->val);
            ans.push_back(t);
            t.pop_back();
            return;
        }
        t.push_back(r->val);
        solve(r->left,sum-r->val,t);
        solve(r->right,sum-r->val,t);
        t.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        solve(root,targetSum,temp);
        return ans;
    }
};
