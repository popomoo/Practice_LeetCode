#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int freqp[26] = {0};
        int freqs[26] = {0};
        int l = 0;
        int r = p.length() - 1;
        vector<int> res;

        if( s.length() < p.length() || s.length() == 0 )
            return res;

        for( int i = 0 ; i < p.length(); i++ )
        {
            freqp[p[i] - 'a']++;
            freqs[s[i] - 'a']++;
        }

        while( r + 1 < s.length() )
        {
            if( isSame( freqs, freqp, 26 ) )
                res.push_back(l);

            freqs[s[++r] - 'a']++;
            freqs[s[l++] - 'a']--;
        }

        if( isSame( freqs, freqp, 26 ) )
                res.push_back(l);

        return res;
    }

    bool isSame( int *s, int *p, int length )
    {
        for( int i = 0; i < length; i++ )
        {
            if( s[i] != p[i] )
                return false;
        }
        return true;
    }
};