class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>, vector<string>> hashMap;
        for(int i=0; i<strs.size(); i++) {
            vector<int> freq(26, 0);
            for(int j=0; j<strs[i].size(); j++) {
                int ind = strs[i][j] - '0' - 49;
                freq[ind]++;
            }
            hashMap[freq].push_back(strs[i]);
        }
        for(auto it: hashMap) {
            ans.push_back(it.second);
        }
        return ans;
    }
};