class Solution {
public:
    bool checkPerfectNumber(int num) {
        
        if(num <= 1)
            return false;

        int sum = 0;

        for(int i = 1; i < num; i++) {
            if(num % i == 0) {
                sum += i;
            }
        }

        return sum == num;

    }
};