 vector<int> temp,ans;
 void solve(TreeNode* root,int b)
 {
     if(root==NULL)
       return;
     if(root->val==b)
     {
         temp.push_back(b);
         ans = temp;
         temp.pop_back();
         return;
     }
     temp.push_back(root->val);
     solve(root->left,b);
     solve(root->right,b);
     temp.pop_back();
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    solve(A,B);
    return ans;
}
