class Solution {
public:

    TreeNode* LowestCommonAncestor(TreeNode* r,int s,int e)
    {
       if(!r||r->val==s||r->val==e)
           return r;
        TreeNode* a=LowestCommonAncestor(r->left,s,e);
        TreeNode* b=LowestCommonAncestor(r->right,s,e);
        if(a&&b)
        return r;
        if(a)
        return a;
        else
        return b;
    }
    string final1="",final2="";
    void pathFromRoot(TreeNode* r,int f,string& a)
    {
        if(!r)return;
        if(r->val==f)
        {
            final1=a;
            return;
        }
        a+='U';
        pathFromRoot(r->left,f,a);
        pathFromRoot(r->right,f,a);
        a.pop_back();
    }
    void pathFromNode(TreeNode* r,int f,string& b)
    {
        if(!r)return;
        if(r->val==f)
        {
            final2=b;
            return;
        }
        b+='L';
        pathFromNode(r->left,f,b);
        b.pop_back();
        b+='R';
        pathFromNode(r->right,f,b);
        b.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* temp=LowestCommonAncestor(root,startValue,destValue);
        string a="",b="";
        TreeNode* x=temp;
        pathFromRoot(x,startValue,a);
        pathFromNode(temp,destValue,b);
        return final1+final2;    
        }
};
