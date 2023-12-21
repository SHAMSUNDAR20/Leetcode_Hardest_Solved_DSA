class Solution {
public:
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> map;
        
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            reverse(word.begin(), word.end());
            map[word] = i;
        }
        
        if (map.find("") != map.end()) {
            for (int i = 0; i < words.size(); i++) {
                if (i != map[""] && isPalindrome(words[i], 0, words[i].size() - 1)) {
                    res.push_back({map[""], i});
                }
            }
        }
        
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].length(); j++) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                
                if (map.find(left) != map.end() && isPalindrome(right, 0, right.length() - 1) && map[left] != i) {
                    res.push_back({i, map[left]});
                }
                if (map.find(right) != map.end() && isPalindrome(left, 0, left.length() - 1) && map[right] != i) {
                    res.push_back({map[right], i});
                }
            }
        }
        
        return res;
    }
};
