class Solution {
public:
    struct TrieNode {
        int count;
        TrieNode* children[26];

        TrieNode() {
            count = 0;
            for(int i=0;i<26;i++)
            children[i]=NULL;
        }
    };
    TrieNode* root;
    void insert(string& word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->children[word[i] - 'a'])
                temp = temp->children[word[i] - 'a'];
            else {
                temp->children[word[i] - 'a'] = new TrieNode();
                temp = temp->children[word[i] - 'a'];
            }
            temp->count++;
        }
    }
    
    int calculateScore(string& word) {
        TrieNode* temp = root;
        int score = 0;
        for (int i = 0; i < word.size(); i++) {
            if (temp->children[word[i] - 'a'])
                temp = temp->children[word[i] - 'a'];
            score += temp->count;
        }
        return score;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        root = new TrieNode();
        for (auto word : words)
            insert(word);
        
        vector<int> scores;
        for (auto word : words) {
            int score = calculateScore(word);
            scores.push_back(score);
        }
        return scores;
    }
};
