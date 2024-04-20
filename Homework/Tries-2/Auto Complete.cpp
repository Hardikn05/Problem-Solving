class AutoCompleteSystem {
public:
    struct TrieNode {
        unordered_map<string,int> suggestions;
        TrieNode* children[27];
        TrieNode(){
            memset(children,NULL,sizeof(children));
        }
    };
    
    int getMask(char c) {
        if(c == ' ')
            return 0;
        return c - 'a' + 1;
    }
    
    void storeSuggestion(string s, int priority) {
        TrieNode* current = root;
        for(auto it: s) {
            if(current->children[getMask(it)] == NULL)
                current->children[getMask(it)] = new TrieNode();
            current = current->children[getMask(it)];
            if(current->suggestions.find(s) == current->suggestions.end()) {
                if(current->suggestions.size() < 3)
                    current->suggestions[s] = priority;
                else {
                    int minPriority = INT_MAX;
                    string minSuggestion;
                    for(auto pair: current->suggestions) {
                        if(minPriority > pair.second) {
                            minPriority = pair.second;
                            minSuggestion = pair.first;
                        }
                    }
                    for(auto pair: current->suggestions) {
                        if(minPriority == pair.second)
                            minSuggestion = max(minSuggestion, pair.first);
                    }
                    if(minPriority < priority || (minPriority == priority && s < minSuggestion)) {
                        current->suggestions.erase(minSuggestion);
                        current->suggestions[s] = priority;
                    }
                }
            }
            else
                current->suggestions[s] = max(current->suggestions[s], priority);
        }
    }
    
    string currentInput;
    TrieNode* root;
    unordered_map<string,int> frequencyMap;
    
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        vector<pair<string,int>> sentencePriorityPairs;
        for(int i = 0; i < sentences.size(); i++)
            sentencePriorityPairs.push_back({sentences[i], times[i]});
        sort(sentencePriorityPairs.begin(), sentencePriorityPairs.end());
        currentInput = "";
        frequencyMap.clear();
        for(auto pair: sentencePriorityPairs) {
            storeSuggestion(pair.first, pair.second);
            frequencyMap[pair.first] = pair.second;
        }
    }
    
    vector<string> getSuggestions(string prefix) {
        TrieNode* current = root;
        for(auto it: prefix) {
            if(current->children[getMask(it)] == NULL)
                return {};
            current = current->children[getMask(it)];
        }
        vector<string> suggestions;
        vector<pair<int,string>> temp;
        for(auto pair: current->suggestions)
            temp.push_back({pair.second, pair.first});
        sort(temp.begin(), temp.end(), [](auto a, auto b) {
            if(a.first > b.first)
                return true;
            else if(a.first == b.first && a.second < b.second)
                return true;
            else
                return false;
        });
        for(auto pair: temp)
            suggestions.push_back(pair.second);
        return suggestions;
    }
    
    vector<string> input(char c) {
        if(c == '#') {
            frequencyMap[currentInput]++;
            storeSuggestion(currentInput, frequencyMap[currentInput]);
            currentInput = "";
            return {};
        }
        currentInput += c;
        vector<string> suggestions = getSuggestions(currentInput);
        return suggestions;
    }
};
