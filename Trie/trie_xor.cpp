//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
class Solution {
public:
    class TrieNode{
        public:
            vector<TrieNode*> edg;
            TrieNode(){
                edg.resize(2);
                edg[0] = NULL , edg[1] = NULL;
            }
    };
    
    void insert(TrieNode* root , int num){
        for(int i = 31 ; i >= 0 ; i--){
            int id = ((1 << i) & num ? 1 : 0);
            if(root -> edg[id] == NULL){
                root -> edg[id] = new TrieNode;
            }
            root = root -> edg[id];
        }
    }
    
    int find(TrieNode* root , int num){
        int res = 0;
        for(int i = 31 ; i >= 0 ; i--){
            int id = ((1 << i) & num ? 0 : 1) ; 
            if(root -> edg[id] != NULL){
                res |= (1 << i);
                root = root -> edg[id];
            } else root = root -> edg[id ^ 1];
            
        }
        return res;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* trieNode = new TrieNode();
        TrieNode* root;
        
        for(auto &num : nums){
            root = trieNode;
            insert(root , num);
        }
        int ans = INT_MIN;
        for(auto &num : nums){
            root = trieNode;
            ans = max(ans , find(root , num));
        }
        return ans;
    }
};
