class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.size();
        int m = needle.size();

        for( int i = 0 ;  i <= n - m ; i++ ){    // we dont hav to iterative till n -> ( n - m ) will done

            int j = 0 ;          // check everytime from start of needle

            while( j < m ){

                if( haystack[ i + j ] != needle[ j ] ){
                    break;
                }

                j++;
            }

            if( j == m ){         // pattern found return index of haystack
                return i;
            }
        }

        return -1;
    }
};