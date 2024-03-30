class Solution {
public:
    bool solve(TreeNode* root,int target,int sum){
        if(root==NULL)
        return false;
        sum += root->val;
        if(sum==target && root->left==NULL && root->right==NULL)
        {
            return true;
        }
        else{
            return solve(root->left,target,sum)||solve(root->right,target,sum);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum,0);
    }
};
