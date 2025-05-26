class Solution {
public:

    vector<int> splitString(string version) {
        vector<int> array;
        string num = "";
        for(int i=0; i < version.size(); i++) {
            if(version[i] == '.') {
                array.push_back(stoi(num));
                num = "";
            } else {
                num += version[i];
            }
        }
        array.push_back(stoi(num));
        return array;
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1 = splitString(version1), v2 = splitString(version2);
        int n = v1.size(), m = v2.size();
        int i = 0, j = 0;
        while(i < n && j <m) {
            if(v1[i] > v2[j]) {
                return 1;
            } else if(v1[i] < v2[i]) {
                return -1;
            }
            i++; j++;
        }
        while(i < n) {
            if(v1[i] > 0) {
                return 1;
            }
            i++;
        }
        while(j < m) {
            if(v2[j] > 0) {
                return -1;
            }
            j++;
        }
        return 0;
    }
};