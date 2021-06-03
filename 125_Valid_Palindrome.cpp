#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        int l = 0;
        int r = s.length() - 1;

        while( l <= r )
        {
            if( s[l] >= 'a' && s[l] <= 'z' )
            {
                if( s[r] >= 'a' && s[r] <= 'z' )
                {
                    if( s[r] == s[l] )
                    {
                        l++;
                        r--;
                    }
                    else
                        return false;
                }
                else if( s[r] >= 'A' && s[r] <= 'Z' )
                {
                    if( s[r] == s[l] + ('A' - 'a') )
                    {
                        l++;
                        r--;
                    }
                    else
                        return false;
                }
                else if( s[r] >= '0' && s[r] <= '9' )
                    return false;
                else
                    r--;
            }
            else if( s[l] >= 'A' && s[l] <= 'Z' )
            {
                if( s[r] >= 'A' && s[r] <= 'Z' )
                {
                    if( s[r] == s[l] )
                    {
                        l++;
                        r--;
                    }
                    else
                        return false;
                }
                else if( s[r] >= 'a' && s[r] <= 'z' )
                {
                    if( s[r] == s[l] + ('a' - 'A') )
                    {
                        l++;
                        r--;
                    }
                    else
                        return false;
                }
                else if( s[r] >= '0' && s[r] <= '9' )
                    return false;
                else
                    r--;
            }
            else if( s[l] >= '0' && s[l] <= '9' )
            {
                if( s[r] >= '0' && s[r] <= '9' )
                {
                    if( s[r] == s[l] )
                    {
                        l++;
                        r--;
                    }
                    else
                        return false;
                }
                else if( (s[r] >= 'a' && s[r] <= 'z') || (s[r] >= 'A' && s[r] <= 'Z') )
                    return false;
                else
                    r--;
            }
            else
                l++;
        }
        return true;
    }
};