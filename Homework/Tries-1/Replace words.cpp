class Solution {
public:
    class TrieNode {
    public:
        TrieNode* child[26];
        bool isEnd;
        TrieNode() {
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
            isEnd = false;
        }
    };

    class Trie {
        TrieNode* root;

    public:
        Trie() {
            root = new TrieNode();
        }

        void insert(TrieNode* root, string word) {
            TrieNode* curr = root;
            for (char c : word) {
                if (curr->child[c - 'a'] == NULL)
                    curr->child[c - 'a'] = new TrieNode();
                curr = curr->child[c - 'a'];
            }
            curr->isEnd = true;
        }

        void insert(string word) {
            insert(root, word);
        }

        string replace(string word) {
            TrieNode* curr = root;
            string prefix = "";
            for (char c : word) {
                if (curr->child[c - 'a'] == NULL || curr->isEnd)
                    break;
                prefix += c;
                curr = curr->child[c - 'a'];
            }
            return curr->isEnd ? prefix : "";
        }
    };

    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* root = new Trie();
        for (const string& word : dictionary)
            root->insert(word);

        vector<string> words;
        string temp = "";
        for (char c : sentence) {
            if (c == ' ') {
                if (!temp.empty())
                    words.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        if (!temp.empty())
            words.push_back(temp);

        string ans = "";
        for (const string& word : words) {
            string temp = root->replace(word);
            if (temp.empty())
                ans += word;
            else
                ans += temp;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};
