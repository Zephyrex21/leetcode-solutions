class Solution {
public:
    bool isPowerOfThree(int n) {
        int ans = n > 0 && 1162261467 % n == 0;
        return ans;
    }
};