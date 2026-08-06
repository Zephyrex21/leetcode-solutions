class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        
        bool bulky = false ;
        bool heavy = false ;
        
        // calculating volume
        long long volume = (long long)length * width * height ;
        
        // check for bulky -> make bool bulky true
        if( length >= 10000 || width >= 10000 || height >= 10000 || volume >= 1000000000 ) {
            bulky = true;
        }
        
        // Check heavy -> make bool heavy true 
        if( mass >= 100 ) {
            heavy = true;
        }
        
        // Final decisions on basis of bulky ans heavy
        if( bulky && heavy )return "Both";
        else if ( bulky ) return "Bulky";
        else if ( heavy ) return "Heavy";
        else return "Neither";
    }
};