class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int  n = bills.size();
        int note_5 = 0, note_10 = 0;
        for(int i=0; i<n; i++) {
            if(bills[i] == 5) {
                note_5++;
            } else if(bills[i] == 10) {
                if(note_5 > 0) {
                    note_5--;
                    note_10++;
                } else {
                    return false;
                }
            } else {
                if(note_5 > 0 && note_10 > 0) {
                    note_5--;
                    note_10--;
                } else if (note_5 >=3) {
                    note_5 -= 3;
                } else {
                    return false;
                }
            }
            cout<<note_5<<" "<<note_10<<endl;
        }
        return true;
    }
};