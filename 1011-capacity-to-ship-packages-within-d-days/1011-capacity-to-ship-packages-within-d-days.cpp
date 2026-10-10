class Solution {
private: 
    int countDays( vector<int> &weights , int cap ){
        int day = 1;
        int load = 0;

        for( int i = 0 ; i< weights.size() ; i++ ){
            if( load + weights[i] > cap ){
                day++;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return day;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element( weights.begin() , weights.end() );
        int high = 0;

        for( int i = 0; i< weights.size(); i++){
            high += weights[i];
        }
        
        int ans = high;

        while( low <= high ){
            int mid = (low + high)/2;

            int daysReq = countDays( weights, mid );

            if( daysReq <= days ){
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