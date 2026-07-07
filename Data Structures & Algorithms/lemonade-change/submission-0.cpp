class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives=0;
        int tens=0;

        for(int i=0;i<bills.size();i++) {
            if(bills[i]==5){
                fives++;
            }
            if(bills[i]==10) {
                if(fives >= 1){
                    fives--;
                    tens++;
                } else {
                    return false;
                }
            }
            if(bills[i]==20) {
                if(tens >= 1 && fives >= 1) {
                    tens--;
                    fives--;
                } else if(tens==0 && fives >= 3) {
                    fives-=3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};