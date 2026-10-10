class Solution {
private:
    bool possible( vector<int> &bloomDay , int day , int m , int k ){
        int count = 0;
        int noofbloom = 0;
        for( int i = 0 ;  i<bloomDay.size() ; i++ ){
            if( bloomDay[i] <= day ){
                count++;
            }
            else{
                noofbloom += ( count/k );
                count = 0;
            }
        }
        noofbloom += ( count/k );

        if( noofbloom >= m ){
            return true;
        }
        else{
            return false;
        }
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
    
        if( n < (long long)m*k ){
            return -1;
        }

        int low = *min_element( bloomDay.begin() , bloomDay.end() );
        int high = *max_element( bloomDay.begin() , bloomDay.end() );

        int ans = high;
        while( low <= high ){
            long long mid = low + (high-low)/2;

            if( possible( bloomDay , mid , m , k )){
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