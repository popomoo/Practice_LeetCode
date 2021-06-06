#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<int, int> record1, record2;
        if( s.length() != t.length() )
            return false;

        for( int i = 0; i < s.length(); i++ )
        {
            record1[s[i]] = t[i];
            record2[t[i]] = s[i];
        }

        for( int i = 0; i < t.length(); i++ )
            if( record1[s[i]] != t[i] || record2[t[i]] != s[i] )
                return false;

        return true;
    }
};