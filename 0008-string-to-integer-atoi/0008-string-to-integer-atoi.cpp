class Solution {
public:
    int myAtoi(string s) {
       int i = 0;
        int n = s.size();

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Read the sign
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        // 3. Set the allowed magnitude
        long long limit = (sign == 1)
                          ? INT_MAX
                          : -(long long)INT_MIN;

        long long num = 0;

        // 4. Read digits and prevent overflow
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            if (num > (limit - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        // 5. Apply the sign
        return (int)(sign * num);
    }
};