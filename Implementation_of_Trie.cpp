
struct Node {
    Node* links[26];
    bool flag = false;
    
    bool containKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    
    void put(char ch,Node* node){
        links[ch - 'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch - 'a'];
    }
    
    void end(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
    
};

class Trie {

private : Node* root;

public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(int i = 0;i < word.size();i ++){
            if(!node->containKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->end();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for(int i = 0;i < word.size();i ++){
            if(!node->containKey(word[i])){
               return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0;i < prefix.size();i ++){
            if(!node->containKey(prefix[i])){
               return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};