class Solution {
private:
    int SumByD( vector<int> &arr , int mid ){
        int sum = 0 ;
        int n = arr.size();
        for( int i = 0 ; i< n ; i++ ){
            sum = sum + ceil((double)arr[i]/(double)(mid) );
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element( nums.begin() , nums.end() );

        while( low <= high ){
            int mid = (low + high )/2;

            if( SumByD( nums, mid ) <= threshold ){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};