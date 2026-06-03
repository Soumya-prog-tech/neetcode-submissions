class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> orders;
        unordered_map<char, int> indegree;
        for(int j = 0; j<words[0].size(); j++) {
            if(indegree.find(words[0][j]) == indegree.end()) indegree[words[0][j]] = 0;
        }
        for(int i = 1; i<words.size(); i++) {
            for(int j = 0; j<words[i].size(); j++) {
                if(indegree.find(words[i][j]) == indegree.end()) indegree[words[i][j]] = 0;
            }
            string curr1 = words[i-1];
            string curr2 = words[i];
            int j = 0; 
            while(j<curr1.size() && j<curr2.size() && curr1[j] == curr2[j]) {
                j++;
            }
            if(j == curr2.size() && j<curr1.size()) return {};
            if(j<curr1.size() && j<curr2.size()) {
                if(orders[curr1[j]].find(curr2[j]) == orders[curr1[j]].end()) {
                orders[curr1[j]].insert(curr2[j]);
                indegree[curr2[j]]++;
                }
            }
            
        }
        queue<char> q;
        string res;
        for(auto& [ch, count] : indegree) {
            if(count == 0) q.push(ch);
        }
        while(!q.empty()) {
            char top = q.front(); 
            q.pop(); 
            res+=top;
            for(auto& nei : orders[top]) {
                indegree[nei] --; 
                if(indegree[nei] == 0) q.push(nei);
            }
        }
        if(res.size() == indegree.size()) return res;
        else return {};
    }
};
