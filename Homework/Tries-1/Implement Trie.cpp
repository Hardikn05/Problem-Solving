class Trienode{
    public:
    Trienode* children[26];
    bool terminal;
    public:
    Trienode()
    {
        for(int i=0;i<26;i++)
        children[i]=NULL;
        terminal = false;
    }
};
class Trie {
    Trienode* root;
public:
    Trie() {
       root = new Trienode();
    }
    void inserting(Trienode * node,string word)
    {
        if(word.size()==0)
        {
            node->terminal=true;
        }
        else
        {
            int index=word[0]-'a';
            Trienode * child = new Trienode();
            if(node->children[index]!=NULL)
            {
                inserting(node->children[index],word.substr(1));
            }
            else
            {
                node->children[index]=child;
                inserting(node->children[index],word.substr(1));
            }
        }
    }
    void insert(string word) {
        inserting(root,word);
    }
    bool searchWord(Trienode* node,string str)
    {
        if(str.size()==0 && node->terminal)
        {
            return true;
        }
        else if(str.size()==0 && !node->terminal)
        return false;
        int index=str[0]-'a';
        if(node->children[index]!=NULL)
        return searchWord(node->children[index],str.substr(1));
        else
        {
            return false;
        }   
    }
    bool search(string word) {
     return searchWord(root,word);
    }
    bool start(Trienode* node,string str)
    {
        if(str.size()==0)
        {
            return true;
        }
        int index=str[0]-'a';
        if(node->children[index]!=NULL)
        return start(node->children[index],str.substr(1));
        else 
        {
            return false;
        }
        
    }
    bool startsWith(string prefix) {
        return start(root,prefix);
    }
};
