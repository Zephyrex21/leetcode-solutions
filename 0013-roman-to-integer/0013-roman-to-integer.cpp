class Solution {
private:
    int getValue(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
public:
    int romanToInt(string s) {
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int current = getValue(s[i]);

            if (i + 1 < n &&
                current < getValue(s[i + 1])) {
                ans -= current;
            }
            else {
                ans += current;
            }
        }

        return ans;
    }
};