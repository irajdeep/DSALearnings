//my submission to https://leetcode.com/problems/map-sum-pairs/description/
class MapSum {
public:
    /** Initialize your data structure here. */
    class Node{
        public:
            vector<Node*> c;
            vector<int> val;
            Node(int v){
                c.resize(27);
                val.push_back(v);
                for(int i = 0 ; i < 27 ; i++) c[i] = NULL;
            }
    };
    map<string , int> seen;
    
    // root with val -1
    Node* trieNode;
    MapSum() {
        trieNode = new Node(-1);    
    }
    
    void insert(string key, int val) {
        if(seen.find(key) != seen.end()) val -= seen[key];
        else seen[key] = val;
        
        int len = key.length();
        Node* root = trieNode;
        
        for(int i = 0 ; i < len ; i++){
           int id = key[i] - 'a';
           if(root -> c[id] == NULL){
               Node* tmp = new Node(val);
               root -> c[id] = tmp;
           }
           else (root -> c[id] -> val).push_back(val);
           root = root -> c[id];
        }
    }
    
    int sum(string prefix) {
        int len = prefix.length();
        Node* root = trieNode;
        
        int ans = 0;
        for(int i = 0 ; i < len ; i++){
            int id = prefix[i] - 'a';
            if(root -> c[id] != NULL) root = root -> c[id];
            else break;
            if(i == len - 1){
                for (auto& e : root -> val){
                    ans += e;
                }
            }
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
