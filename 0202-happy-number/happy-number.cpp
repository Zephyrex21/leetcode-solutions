class Solution {
private:
    long long getNext( int n ){

        long long sum = 0 ;
        while( n > 0 ){
            long long digit = n % 10;
            sum = sum + digit * digit ;
            n = n / 10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        
        unordered_set<int> seen;
        while( n != 1 ){

            if( seen.count(n) ){
                return false;       //  cycle detected
            }
            seen.insert(n);
            n = getNext(n);
        }
        return true;   // reached 1
    }
};