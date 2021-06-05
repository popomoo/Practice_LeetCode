#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l = 0;
        int r = -1;
        int freq[256] = {0};
        int res = 0;

        while( l < s.length() )
        {
            if( r + 1 < s.length() && freq[s[r+1]] == 0 )
                freq[s[++r]]++;
            else
                freq[s[l++]]--;

            res = max(res, r - l + 1 );
        }

        return res;
    }
};