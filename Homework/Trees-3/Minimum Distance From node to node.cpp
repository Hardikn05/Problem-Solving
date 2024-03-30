class Solution{
    public:
    Node* LowestCommonAncestor(Node* root,int s,int e)
    {
       if(!root||root->data==s||root->data==e)
           return root;
        Node* a=LowestCommonAncestor(root->left,s,e);
        Node* b=LowestCommonAncestor(root->right,s,e);
        if(a&&b)
        return root;
        if(a)
        return a;
        else
        return b;
    }
    long long Distance(Node* root,int a)
    {
        if(root==NULL)
           return INT_MAX;
           
        if(root->data == a)
          return 0;
          
        return 1+min(Distance(root->left,a),Distance(root->right,a));
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* LCA = LowestCommonAncestor(root,a,b);
        long long d1 = Distance(LCA,a);
        long long d2 = Distance(LCA,b);
        return int(d1+d2);
    }
};
