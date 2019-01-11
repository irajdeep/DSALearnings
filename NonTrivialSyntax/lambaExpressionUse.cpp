//https://leetcode.com/problems/design-search-autocomplete-system/description/

class AutocompleteSystem {
public:
    class CustomComparator{
        public:
          bool operator()(pair<int , string>& p1 , pair<int , string>& p2){
              if(p1.first != p2.first){
                  return p1.first > p2.first;
              }
              return p1.second < p2.second;
          }  
    };
    priority_queue<pair<int , string> , vector<pair<int , string>> , CustomComparator> pq;
    map<string , int> mp;
    string tmp;

    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        int len = (int)sentences.size();
        pq =  priority_queue<pair<int , string> , vector<pair<int , string>> , CustomComparator>() ;
        mp.clear();
        tmp.clear();
        for(int i = 0 ; i < len ; i++){
            mp[sentences[i]] = times[i];
        }
    }
    
    vector<string> input(char c){
        if(c == '#'){
            mp[tmp] += 1;
            tmp.clear();
            return {};
        }
        tmp.push_back(c);
        int len = (int)tmp.length();
        vector<string> ans;
        
        for(auto& e : mp){
            string t = e.first;
            int i = 0;
            for(i = 0 ; i < len ; i++){
                if(t[i] != tmp[i]) break;        
            }
            if(i == len) pq.push(make_pair(e.second , t));
            if((int)pq.size() > 3) pq.pop();
            
        }
        while(!pq.empty()){
            auto e = pq.top();
            pq.pop();
            ans.push_back(e.second);
        }
        sort(ans.begin(), ans.end(), [&mp = mp](string &s1, string &s2){ 
            if(mp[s1] != mp[s2]) return mp[s1] > mp[s2]; 
             else return s1 < s2;});
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */
