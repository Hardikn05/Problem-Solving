//BRUTE FORCE - TC:= O(n²)
class Solution {
public:
    TreeNode* leftmax(TreeNode* root)
    {
        root=root->left;
        if(!root) return NULL;
        while(root->right)
        {
            root=root->right;
        }
        return root;
    }
    TreeNode* rightmin(TreeNode* root)
    {
        root=root->right;
        if(!root) return NULL;

        while(root->left)
        {
            root=root->left;
        }

        return root;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        TreeNode* max = leftmax(root);
        TreeNode* min = rightmin(root);
        bool ans = true;
        if(max!=NULL)
             ans = max->val<root->val;
        if(min!=NULL)
            ans = ans && min->val>root->val;
        
        return ans && isValidBST(root->left) && isValidBST(root->right);
    }
};
// OPTIMISED APPROACH - TC:=O(n)
class Solution {
public:
    bool check(TreeNode* root,long long mini,long long maxi)
    {
        if(!root) return true;
        
        if(1LL*root->val>=maxi|| 1LL*root->val<=mini) return false;

        return check(root->left,mini,root->val) && check(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) {
        return check(root,LONG_MIN,LONG_MAX);
    }
};
