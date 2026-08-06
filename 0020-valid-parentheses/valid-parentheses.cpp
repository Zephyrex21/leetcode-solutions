class Solution {
public:
    bool isValid(string s) {
    
    stack<char> str ;

    for( int i = 0 ; i < s.length() ; i++ ){

        char ch = s[i] ;

        //  if opening bracket -> push in stack
        if( ch == '{' || ch == '[' || ch == '(' ){
            str.push(ch);
        }
        else{

            //for closing bracket -> check top of stack and pop
            if( ! str.empty() ){
                char top = str.top();

                if( ( ch == ')' && top == '(' ) ||
                 ( ch == '}' && top == '{' ) ||
                 ( ch == ']' && top == '[' ) ){
                    str.pop() ;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if( str.empty() ){
        return true;
    }
    else{
        return false;
    }
    }
};