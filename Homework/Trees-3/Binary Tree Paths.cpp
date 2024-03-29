/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,vector<string> &ans,string temp)
    {
        if(root == NULL)
        return;

        temp+=to_string(root->val);
        temp+="->";

        if(root->right==NULL &&root->left==NULL)
        {
            temp.pop_back();
            temp.pop_back();
            ans.push_back(temp);
            return;
        }

        solve(root->left,ans,temp);
        solve(root->right,ans,temp);

    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == NULL)
        return ans;

        solve(root,ans,"");
        return ans;    
        }
};
