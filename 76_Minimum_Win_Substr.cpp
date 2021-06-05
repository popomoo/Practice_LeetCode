#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        int l = 0;
        int r = t.length();
        string res = "";
        int resLen = s.length();
        int freqt[58] = {0};
        int freqs[58] = {0};

        if( s.length() < t.length() || t.length() <= 0 )
            return res;

        for( int i = 0; i < t.length(); i++ )
        {
            freqt[t[i] - 'A']++;
            freqs[s[i] - 'A']++;
        }

        if( Cover( freqs, freqt, 58 ) )
        {
            res = s.substr(l, r - l );
            resLen = res.length();
            if( (r - l) >= t.length() )
                freqs[s[l++] - 'A']--; 
        }

        while( l <= s.length() - t.length() )
        {
            if( (freqt[s[l] - 'A'] == 0 || freqs[s[l] - 'A'] > freqt[s[l] - 'A'])
                && (l < r) )   
                freqs[s[l++] - 'A']--;
            else if( r < s.length() )
                freqs[s[r++] - 'A']++;
            else
                break;

            if( Cover( freqs, freqt, 58 ) )
            {
                if( (r - l) <= resLen )
                {
                    res = s.substr(l, r - l);
                    resLen = res.length();
                }
                if( (r - l) >= t.length() )
                    freqs[s[l++] - 'A']--; 
                else
                    break;
            }
        }

        return res;
    }

    bool Cover( int *s, int *t, int length )
    {
        for( int i = 0; i < length; i++ )
        {
            if( t[i] != 0 && s[i] < t[i] )
                return false;
        }
        return true;
    }
};