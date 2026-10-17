class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                int freq[26] = {0};

                // Count frequencies of this substring
                for (int k = i; k <= j; k++) {
                    freq[s[k] - 'a']++;
                }

                int maxFreq = 0;
                int minFreq = INT_MAX;

                // Find maximum and minimum non-zero frequencies
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                ans += maxFreq - minFreq;
            }
        }

        return ans;
    }
};