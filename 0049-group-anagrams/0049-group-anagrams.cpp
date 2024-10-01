class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> hashMap;
        for(int i=0; i<strs.size(); i++) {
            vector<int> freq(26, 0);
            string s = strs[i];
            sort(s.begin(), s.end());
            hashMap[s].push_back(strs[i]);
        }
        for(auto it: hashMap) {
            ans.push_back(it.second);
        }
        return ans;
    }
};