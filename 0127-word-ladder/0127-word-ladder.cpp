class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st{wordList.begin(), wordList.end()};
        st.erase(beginWord);
        while(!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();
            if(word == endWord) {
                return steps;
            }
            for(int i=0; i<word.size(); i++) {
                int originalLetter = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = originalLetter;
            }
        }
        return 0;
    }
};