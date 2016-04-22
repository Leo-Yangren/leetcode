class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> m;
        vector<vector<int>> result;
        
        
        for(int i=0; i< words.size(); i++){
            m[words[i]] = i;
        }
        
        for(int i=0; i< words.size(); i++){
            if(words[i] == ""){
                continue;
            }
            
            if(isvalid(words[i]) && words[i].size()>0){
                if(m.count("")){
                    result.push_back({i,m[""]});
                    result.push_back({m[""],i});
                }
            }
            string temp = words[i];
            reverse(temp.begin(),temp.end());
            
            if(m.count(temp) && m[temp]!= i){
                result.push_back({i,m[temp]});
            }
            
            for(int k =1; k<words[i].size();k++){
                string s1 = words[i].substr(0,k);
                string s2 = words[i].substr(k,words[i].size() - k);
                
                string s1_t = s1;
                string s2_t = s2;
                reverse(s1_t.begin(),s1_t.end());
                reverse(s2_t.begin(),s2_t.end());
                
                if(isvalid(s1) && m.count(s2_t)&&m[s2_t]!=i){
                    result.push_back({m[s2_t],i});
                }
                
                
                if(isvalid(s2) && m.count(s1_t)&&m[s1_t]!=i){
                    result.push_back({i,m[s1_t]});
                }
            }
        }
      return result;
    }
    
    bool isvalid(string s){
        int j = s.size()/2;
        for(int i = 0; i<j;i++){
            if(s[i] != s[s.size()-1-i]){
                return false;
            }
        }
        return true;    
    }
    
    
};