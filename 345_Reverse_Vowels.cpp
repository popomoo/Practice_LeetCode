#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {

        int l = 0;
        int r = s.length() - 1;

        while( l <= r )
        {
            if( s[l] == 'a' || s[l] == 'A' ||
                s[l] == 'e' || s[l] == 'E' ||
                s[l] == 'i' || s[l] == 'I' ||
                s[l] == 'o' || s[l] == 'O' ||
                s[l] == 'u' || s[l] == 'U'  )
            {
                if( s[r] == 'a' || s[r] == 'A' ||
                    s[r] == 'e' || s[r] == 'E' ||
                    s[r] == 'i' || s[r] == 'I' ||
                    s[r] == 'o' || s[r] == 'O' ||
                    s[r] == 'u' || s[r] == 'U' )
                    swap( s[l++], s[r--] );
                else
                    r--;
            }
            else
                l++;
        }

        return s;
    }
};