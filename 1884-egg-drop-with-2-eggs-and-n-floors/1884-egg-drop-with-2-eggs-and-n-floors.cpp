class Solution {
public:
    int twoEggDrop(int n) {
        int sum = 0;
        int step = 0;
        while(n > sum) {
            step++;
            sum += step;
        } 
        return step;
    }
};