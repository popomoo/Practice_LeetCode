#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {

        if( path[path.length() - 1] != '/' )
            path += "/";

        stack<string> stack;
        string file = "";

        for( int i = 0; i < path.length(); i++ )
        {
            if( path[i] == '/')
            {
                if( file == ".." && !stack.empty() )
                    stack.pop();
                else if( file != "." && file != ".." && !file.empty() )
                    stack.push( file );
                file.clear();
            }
            else
                file += path[i];
        }

        string res;
        while( !stack.empty() )
        {
            string temp = stack.top();
            stack.pop();
            res = "/" + temp + res;
        }

        if( res.empty() )
            res = "/";

        return res;
    }
};