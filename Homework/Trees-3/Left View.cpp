void solve(BinaryTreeNode<int>* r,int x,vector<int> &ans)
{
    if(r==NULL)
      return;
    if(ans.size()<x+1)
    ans.push_back(r->data);
    solve(r->left,x+1,ans);
    solve(r->right,x+1,ans);
}
vector<int> printLeftView(BinaryTreeNode<int>* root) {
    vector<int> ans;
    solve(root,0,ans);
    return ans;
}
