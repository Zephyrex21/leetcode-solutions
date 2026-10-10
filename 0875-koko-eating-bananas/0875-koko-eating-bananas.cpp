class Solution {
private:
    long long totalHrs( vector<int> &piles, int mid ){
        long long totalhrs = 0;
        int n = piles.size();
        for( int i = 0 ; i<n ; i++ ){
            totalhrs += ceil( (double)piles[i]/(double)mid );
        }
        return totalhrs;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element( piles.begin() , piles.end() );
        int ans =INT_MAX;

        while( low <= high ){
            int mid = (low + high)/2;

            long long totalhr = totalHrs( piles , mid );

            if( totalhr <= h ){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};