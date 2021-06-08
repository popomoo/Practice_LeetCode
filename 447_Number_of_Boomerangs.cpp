#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {

        int res = 0;
        for( int i = 0; i < points.size(); i++ )
        {
            unordered_map<int, int> record;
            for( int j = 0; j < points.size(); j++ )
                if( j != i )
                    record[ distance( points[i], points[j] ) ]++;

            for( auto iter = record.begin(); iter != record.end(); ++iter )
                res += (iter->second)*(iter->second - 1);
        }
        return res;
    }

    int distance( const vector<int> &a, const vector<int> &b )
    {
        return (b[0] - a[0])*(b[0] - a[0]) + (b[1] - a[1])*(b[1] - a[1]);
    }
};