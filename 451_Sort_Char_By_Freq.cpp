#include <unordered_map>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> record;
        string res;

        if( s.length() == 0 )
            return "";

        for( int i = 0; i < s.length(); i++ )
            record[s[i]]++;

        vector<pair<char, int>> v( record.begin(), record.end() );
        vector<string> buckets(s.length() + 1);
        for( auto &elem : v )
            buckets[elem.second].append(elem.second, elem.first);
        
        for( int i = buckets.size() - 1; i >= 0; i-- )
        {
            if( buckets[i].size() != 0 )
                res.append(buckets[i]);
        }

        return res;
    }
};