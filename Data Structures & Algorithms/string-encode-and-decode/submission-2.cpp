class Solution {
public:

    string encode(vector<string>& strs) {
        string enc;
        for(int i =0 ; i<strs.size(); i++) {
            enc += to_string(strs[i].size());
            enc += "#";
            enc += strs[i];
        }
        return enc;
    }

    vector<string> decode(string s) {
        int index = 0;
        int n = s.size();
        vector<string> decoded;
        while(index < n) {
            string strlength;
            while(s[index] != '#') {
                strlength.push_back(s[index]);
                index ++;
            }
            int strlengthi = stoi(strlength);
            if(strlengthi == 0) {
                decoded.push_back("");
                index++;
                continue;
            }
            string temp;
            for(int i = index+1;i<index+1+strlengthi; i++) {
                temp.push_back(s[i]);
            }
            decoded.push_back(temp);
            index+= strlengthi + 1;
        }
        return decoded;
    }
};
