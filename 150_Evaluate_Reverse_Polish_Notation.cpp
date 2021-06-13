#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> stk;
        int res = 0;

        for( int i = 0; i < tokens.size(); i++ )
        {
            string &token = tokens[i];
            if( token != "+" && token != "-" && token != "*" && token != "/" )
                stk.push( atoi(token.c_str() ) );
            else
            {
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();

                switch( token[0] )
                {
                    case '+' :  res = y + x; 
                                stk.push(res);
                                break;
                    case '-' :  res = y - x;
                                stk.push(res); 
                                break;
                    case '*' :  res = y * x;
                                stk.push(res);
                                break;
                    case '/' :  res = y / x;
                                stk.push(res);
                                break;
                    default : break;
                }
            }
        }
        return stk.top();
    }
};