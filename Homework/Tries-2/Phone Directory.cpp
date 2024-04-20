class Solution{
public:
    struct TrieNode{
        TrieNode* children[26];
        vector<int> indices;
        TrieNode() {
            memset(children, NULL, sizeof(children));
        }
    };
    
    TrieNode* root;
    
    void insert(string word, int idx) {
        TrieNode* node = root;
        for(auto ch : word) {
            if(node->children[ch - 'a'] == NULL)
                node->children[ch - 'a'] = new TrieNode();
            node = node->children[ch - 'a'];
            node->indices.push_back(idx);
        }
    }
    
    vector<string> search(string query, string* contacts) {
        TrieNode* node = root;
        vector<string> result;
        for(auto ch : query) {
            if(node->children[ch - 'a'] == NULL)
                return result;
            node = node->children[ch - 'a'];
        }
        for(auto idx : node->indices)
            result.push_back(contacts[idx]);
        return result;
    }
    
    vector<vector<string>> displayContacts(int n, string contact[], string query) {
        root = new TrieNode();
        unordered_set<string> visited;
        for(int i = 0; i < n; i++) {
            if(visited.find(contact[i]) == visited.end())
                insert(contact[i], i);
            visited.insert(contact[i]);
        }
        
        vector<vector<string>> result;
        string subQuery;
        for(auto ch : query) {
            subQuery += ch;
            vector<string> contacts = search(subQuery, contact);
            sort(contacts.begin(), contacts.end());
            if(contacts.empty())
                result.push_back({"0"});
            else
                result.push_back(contacts);
        }
        return result;
    }
};
