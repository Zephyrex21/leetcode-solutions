class Solution {
private:
    bool canweplace( vector<int> &position , int dist , int k ){
        int cowcount = 1; 
        int lastcow = position[0];
        
        for( int i = 1; i < position.size() ; i++ ){
            if( position[i]-lastcow >= dist ){
                cowcount++;
                lastcow = position[i];
                
                if( cowcount == k ){
                    return true;
                }
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        // code here
        sort( position.begin() , position.end() );
        int n = position.size();
        
        int low = 0;
        int high = position[n-1]-position[0];
        
        while( low <= high ){
            
            int mid = ( low + high )/2 ;
            
            if( canweplace( position , mid , m )){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
};