class Solution {
public:

    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalAmount = 0;
        for(int i=0; i<k; i++) {
            totalAmount += cardPoints[i];
        }
        int ans = totalAmount;
        for(int i=0; i<k; i++) {
            totalAmount += cardPoints[n - 1 - i] - cardPoints[k - 1 - i];
            ans = max(ans, totalAmount);
        }
        return ans;
    }
};