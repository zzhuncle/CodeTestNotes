class Trie {
private:
    vector<Trie*> child;
    bool isLeaf;
public:
    Trie() {
        child = vector<Trie*>(26, NULL);
        isLeaf = false;
    }
    
    void insert(string word) {
        Trie *root = this, *p = root;
        for (char ch : word) {
            if (p->child[ch - 'a'] == NULL) {
                p->child[ch - 'a'] = new Trie();
            }
            p = p->child[ch - 'a'];
        }
        p->isLeaf = true;
    }
    
    bool search(string word) {
        Trie *root = this, *p = root;
        for (char ch : word) {
            if (p->child[ch - 'a'] == NULL)
                return false;
            p = p->child[ch - 'a'];
        }
        if (p->isLeaf == false)
            return false;
        return true; 
    }
    
    bool starts(string word) {
        Trie *root = this, *p = root;
        for (char ch : word) {
            if (p->child[ch - 'a'] == NULL)
                return false;
            p = p->child[ch - 'a'];
        }
        return true; 
    }
};
