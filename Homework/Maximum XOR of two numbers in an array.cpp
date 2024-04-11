class Solution {
public:
    class TrieNode{
        public:
        TrieNode* child[2];
        TrieNode()
        {
            child[0]=NULL;
            child[1]=NULL;
        }
        bool contain(int bit)
        {
            return child[bit]!=NULL;
        }
        TrieNode* getbit(int bit)
        {
            return child[bit];
        }
        void setbit(TrieNode* node,int bit)
        {
            child[bit]=node;
        }
    };
    class Trie{
        TrieNode *root;
        public:
        void insert(int num)
        {
            TrieNode *curr = root;
            for(int i=31;i>=0;i--)
            {
                int bit = (num>>i)&1;
                if(!curr->contain(bit))
                {
                    curr->setbit(new TrieNode(),bit);
                }
                curr = curr->getbit(bit);
            }

        }
        int getMax(int num)
        {
            TrieNode* curr = root;
            int ans = 0;
            for(int i=31;i>=0;i--)
            {
                int bit = (num>>i)&1;
                if(curr->contain(!bit))
                {
                    ans+=pow(2,i);
                    curr=curr->getbit(!bit);
                }
                else
                {
                    curr=curr->getbit(bit);
                }
            }
            return ans;
        }
        Trie()
        {
            root = new TrieNode();
        }
    };
    int findMaximumXOR(vector<int>& nums) {
        Trie *root = new Trie();
        for(int i=0;i<nums.size();i++)
          root->insert(nums[i]);

        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            maxi = max(maxi,root->getMax(nums[i]));
        }
        return maxi;
    }
};
