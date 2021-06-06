#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<int, int> record;
        if( s.length() != t.length() )
            return false;

        for( int i = 0; i < s.length(); i++ )
            record[ s[i] ]++;
        
        for( int i = 0; i < t.length(); i++ )
            if( record[ t[i] ] <= 0 )
                return false;
            else
                record[ t[i] ]--;

        return true;
    }
};