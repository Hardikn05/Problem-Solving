class Solution {
public:
    int check_height=-1;
    void solve(TreeNode* root,int curr_height,int &ans)
    {
        if(root==NULL)
        return;

        if(check_height<curr_height)
        {
            ans = root->val;
            check_height = curr_height;
        }
        solve(root->left,curr_height+1,ans);
        solve(root->right,curr_height+1,ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans;
        solve(root,0,ans);
        return ans;
    }
};
