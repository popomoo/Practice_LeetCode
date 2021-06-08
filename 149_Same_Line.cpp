#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        int MaxPoint = 0;
        if( points.size() < 3 )
            return points.size();

        for( int i = 0; i < points.size()/2; i++ )
        {
            unordered_map<string, int> record;
            int SamePoints = 0;
            for( int j = 0; j < points.size(); j++ )
            {
                if( j != i )
                {
                    if( points[i][0] == points[j][0] && points[i][1] == points[j][1] )
                        SamePoints++;
                    else
                    {
                        record[Slope(points[i], points[j] )]++;
                    }
                }
            }
            
            for( auto iter = record.begin(); iter != record.end(); ++iter )
                MaxPoint = max( iter->second + SamePoints, MaxPoint );

            record.clear();
        }
        return MaxPoint + 1;
    }

    string Slope( const vector<int> &X, const vector<int> &Y )
    {
        if( X[0] == Y[0] && X[1] != Y[1] )
            return "1e+300";
        else if( X[1] == Y[1] && X[0] != Y[0] )
            return "0";
        else
        {
            int Delta_X = Y[0] - X[0];
            int Delta_Y = Y[1] - X[1];
            int common = gcd( Delta_X, Delta_Y );
            string s = to_string( Delta_Y/common ) + "/" + to_string( Delta_X/common );
            return s;
        }
    }

    int gcd( int x, int y )
    {
        while( x % y != 0 )
        {
            int z = x % y;
            x = y;
            y = z;
        }
        return y;
    }
};