#include <bits/stdc++.h> 
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
    public : 
    Trie(){
        root = new Node();
    }
    
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
    
    bool checkIfPrefixExits(string &word){
        bool flag = true;
        Node* node = root;
        for(int i = 0;i < word.size();i ++){
            if(node->containKey(word[i])){
                node = node->get(word[i]);
                flag = (flag & node->isEnd());
            }else {
                return false;
            }
        }
        return flag;
    }
    
        
};

string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie* obj = new Trie();
    string longest="";
    for(auto word: a){
        obj->insert(word);
    }
    for(auto word : a){
        if(obj->checkIfPrefixExits(word)){
            if(word.size() > longest.size()){
                longest =word;
            }else if(word.size() == longest.size()){
                if(word < longest){
                    longest = word;
                }
            }
        }
    }
    if(longest == ""){
        longest = "None";
    }
    return longest;
}