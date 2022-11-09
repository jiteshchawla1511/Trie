#include <bits/stdc++.h>
struct Node {
  Node * links[2];
 
  bool containsKey(int ind) {
    return (links[ind] != NULL);
  }
  Node * get(int ind) {
    return links[ind];
  }
  void put(int ind, Node * node) {
    links[ind] = node;
  }
};

class Trie{
    private: Node* root;
    public :
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node = root; 
        for(int i = 31;i >= 0;i --){
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    
    int getMaximum(int num){
        Node* node = root;
        int maxNum = 0;
        for(int i = 31;i >= 0;i --){
            int bit = (num >> i) & 1;
            if(node->containsKey(1 - bit)){
                maxNum = (maxNum | (1 << i)); 
                node = node->get(1 - bit);
            }else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
    
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    //  Write your coode here.
    Trie trie;
    int n = arr.size();
    sort(arr.begin(),arr.end());
    int sz = queries.size();
    vector<pair<int,pair<int,int>>>q;
    for(int i = 0;i < sz;i ++){
        q.push_back({queries[i][1],{queries[i][0],i}});
    }
    sort(q.begin(),q.end());
    vector<int> ans(sz,0);
    int idx = 0;
    for(int i  = 0;i < sz;i ++){
        int ai = q[i].first;
        int xi = q[i].second.first;
        int qInd = q[i].second.second;
        while(idx < n && arr[idx] <= ai){
            trie.insert(arr[idx]);
            idx ++;
        }
        if(idx == 0){
            ans[qInd] = -1;
        }else {
            ans[qInd] = trie.getMaximum(xi);
        }
    }
    return ans;
}