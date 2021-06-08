#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> record;
        for( int i = 0; i < strs.size(); i++ )
        {
            string key = strs[i];
            sort( key.begin(), key.end() );
            record[key].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for( auto i = record.begin(); i != record.end(); ++i )
            res.emplace_back( i->second );

        return res;

    }
};