class TrieNode {
public:
    int count;
    int sum;
    TrieNode* children[2];
    
    TrieNode(){
        count = 0;
        sum = 0;
        children[0] = NULL;
        children[1] = NULL;
    }
};

class Solution {
public:
    TrieNode* root;
    
    int getValue(TrieNode* root, int num, int index){
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
        
            if (root->children[bit] == NULL){
                return 0;
            }
            root = root->children[bit];
        }
        return (((root->count) * index) - (root->sum));
    }
    
    void insert(TrieNode* root, int num, int index){
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if (root->children[bit] == NULL){
                root->children[bit] = new TrieNode();
            }
            root = root->children[bit];
        }
        root->sum += index;
        root->count++;
    }
    
    int countTriplets(vector<int>& arr) {
        root = new TrieNode();
        int answer = 0;
        int xorValue = 0;
        for(int i = 0; i < arr.size(); i++){
            insert(root, xorValue, i);
            xorValue ^= arr[i];
            answer += getValue(root, xorValue, i);
        }
        return answer;
    }
};
