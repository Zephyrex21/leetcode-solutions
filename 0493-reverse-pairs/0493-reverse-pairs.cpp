class Solution {
private:
    int cnt = 0;

    void merge( vector<int> &arr , int low , int mid , int high ){
          
          vector<int> temp;
          int left = low;
          int right = mid+1;
          
          while( left <= mid && right <= high ){
              if( arr[left] <= arr[right] ){
                  temp.push_back( arr[left] );
                  left++;
              }
              else{
                  temp.push_back( arr[right] );
                  right++;
              }
          }
          while( left <= mid ){
            temp.push_back( arr[left] );
            left++;
          }
          while( right <= high ){
            temp.push_back( arr[right] );
            right++;
          }
          
          for(int i = low; i <= high; i++){
              arr[i] = temp[i - low];
          }
    }
    
    void countPairs( vector<int> &arr ,  int low , int mid , int high ){
        long long right = mid+1;
        for( int i = low ; i<= mid ; i++ ){
            while( right <= high && arr[i] > (long long )2*arr[right] ) right++;
            cnt += ( right - (mid+1));
        }
    }

    void mergesort( vector<int> &arr , int low , int high ){
            if( low >= high ){
                return ;
            }
            
            int mid = ( low + high )/2 ;
            
            mergesort( arr , low , mid );
            mergesort( arr , mid+1 , high );
            
            countPairs( arr , low , mid , high );

            merge( arr, low , mid , high );
    }
public:
    int reversePairs(vector<int>& nums) {
        mergesort( nums , 0 , nums.size()-1 );
        return cnt;
    }
};