class Solution {
public:
    const long long MOD = 1000000007;

    // Calculates (x ^ exp) % MOD using recursion
    long long power(long long x, long long exp) {

        // Base case
        if (exp == 0) {
            return 1;
        }

        // Calculate power for half the exponent
        long long half = power(x, exp / 2);

        // Square the result
        long long ans = (half * half) % MOD;

        // If exponent is odd, multiply by x once more
        if (exp % 2 == 1) {
            ans = (ans * x) % MOD;
        }

        return ans;
    }
    
    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;

        long long evenWays = power(5, evenCount);
        long long oddWays = power(4, oddCount);

        return (evenWays * oddWays) % MOD;
    }
};