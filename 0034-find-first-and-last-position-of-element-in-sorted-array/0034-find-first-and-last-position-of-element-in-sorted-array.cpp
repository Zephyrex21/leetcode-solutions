class Solution {
private:
    int first_occur( vector<int>& arr , int n , int k ){
    
        int start = 0 ;
        int end = n-1 ; 
        int mid = start + ( end - start ) / 2 ;
        int ans = -1 ;


        while ( start <= end ){


            if( arr[mid]== k )
            {  
                ans = mid ;
                end  = mid - 1 ;
            } 

            else if ( k > arr[mid])
            {
                start = mid + 1;
            }

            else 
            {
                end = mid - 1 ;
            }

            mid = start + ( end - start ) / 2 ;
        }

        return ans;

    }

    int last_occur( vector<int>& arr , int n , int k ){
    
        int start = 0 ;
        int end = n-1 ; 
        int mid = start + ( end - start ) / 2 ;
        int ans = -1 ;


        while ( start <= end ){


            if( arr[mid]== k )
            {  
                ans = mid ;
                start  = mid + 1 ;
            } 

            else if ( k > arr[mid])
            {
                start = mid + 1;
            }

            else 
            {
                end = mid - 1 ;
            }

            mid = start + ( end - start ) / 2 ;
        }

        return ans;

    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

        int n = nums.size();

        ans.push_back(first_occur(nums,n,target));
        ans.push_back(last_occur(nums,n,target));

        return ans;
    }
};