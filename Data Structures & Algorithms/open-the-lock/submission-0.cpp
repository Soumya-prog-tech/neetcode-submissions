class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int limit = 9;
        string current = "0000";
        queue<string> q;
        q.push(current);
        int ans = 0;
        unordered_set<string> deadend_set;
        for(int i = 0; i<deadends.size(); i++) {
            deadend_set.insert(deadends[i]);
        }
        if(deadend_set.find(current) != deadend_set.end()) return -1;
        unordered_set<string> visited;
        visited.insert(current);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string curr = q.front();
                q.pop();
                if(curr == target) return ans;
                for(int i = 0; i<4; i++) {
                    string temp = curr;
                    if(temp[i] - '0' < 9) {
                        temp[i]++;
                        if(deadend_set.find(temp) == deadend_set.end() && visited.find(temp) == visited.end()) {
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                    else if(temp[i] - '0' == 9) {
                        temp[i] = '0';
                        if(deadend_set.find(temp) == deadend_set.end() && visited.find(temp) == visited.end()) {
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                    temp = curr;
                    if(temp[i] - '0' > 0) {
                        temp[i]--;
                        if(deadend_set.find(temp) == deadend_set.end() && visited.find(temp) == visited.end()) {
                            q.push(temp);
                            visited.insert(temp); 
                        }
                    }
                    else if(temp[i] - '0' == 0) {
                        temp[i] = '9';
                        if(deadend_set.find(temp) == deadend_set.end() && visited.find(temp) == visited.end()) {
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};