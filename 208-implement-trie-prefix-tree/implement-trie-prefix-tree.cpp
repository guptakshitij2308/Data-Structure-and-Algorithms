class Node {
    public:
    Node *referenceNodes[26];
    bool flag=false;
    Node() {
        for (int i = 0; i < 26; i++) {
        referenceNodes[i] = nullptr;
        }
    }
    bool containsKey(char ch) {
        return referenceNodes[ch-'a']!=NULL;
    }
    void insertChar(char ch,Node *node) {
        Node *temp=new Node();
        referenceNodes[ch-'a']=temp;
    }

    Node* getChar(char ch) {
        return referenceNodes[ch-'a'];
    }
    void setEnd() {
        flag=true;
    }
};
class Trie {
private:
    Node *root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node *node=root;
        for(int i=0;i<word.length();i++) {
            if(!(*node).containsKey(word[i])) {
                node->insertChar(word[i],node);
            }
            node=node->getChar(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node=root;
        for(int i=0;i<word.length();i++) {
            if(!node->containsKey(word[i]))
            return false;
            node=node->getChar(word[i]);
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node *node=root;
        for(int i=0;i<prefix.length();i++) {
            if(!node->containsKey(prefix[i]))
            return false;
            node=node->getChar(prefix[i]);
        }
        return true;
    }
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */