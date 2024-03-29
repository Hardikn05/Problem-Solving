class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> bottomView(Node *root)
    {
        //Your code here
        if (root==NULL)
        return {};
        
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));
        vector<int> ans;
        while(!q.empty())
        {
            pair<Node*,int> curr = q.front();
            q.pop();
            mp[curr.second]=curr.first->data;
            if(curr.first->left!=NULL)
            {
                q.push({curr.first->left,curr.second-1});
            }
            if(curr.first->right!=NULL)
            {
                q.push({curr.first->right,curr.second+1});
            }
        }
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }

};
