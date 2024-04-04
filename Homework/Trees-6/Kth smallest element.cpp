class Solution {
public:
    void solve(TreeNode* root,int &k,int &ans)
    {
        if(!root) return;
        solve(root->left,k,ans);
        k--;
        if(k==0)
            ans=root->val;
        solve(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        solve(root,k,ans);
        return ans;
    }
};
class Solution {
public:
    void solve(TreeNode* root,int &k,int &ans)
    {
        if(!root) return;
        solve(root->left,k,ans);
        k--;
        if(k==0)
            ans=root->val;
        solve(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        solve(root,k,ans);
        return ans;
    }
};
