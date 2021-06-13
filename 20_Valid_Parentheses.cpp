#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<int> stack;

        for( int i = 0; i < s.size(); i++ )
        {
            if( (s[i] == '(') || (s[i] == '[') || (s[i] == '{') )
                stack.push( s[i] );
            else
            {
                if( stack.empty() )
                    return false;

                char c = stack.top();
                stack.pop();

                switch(s[i])
                {
                    case ')' :  if( c != '(' ) return false;
                                else break;
                    case '}' :  if( c != '{' ) return false;
                                else break;
                    case ']' :  if( c != '[' ) return false;
                                else break;
                    default : return false;
                }
            }
        }

        if( stack.empty() )
            return true;
        else
            return false;
    }
};