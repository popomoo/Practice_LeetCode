#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> record;
        int sum = 0;

        while( n != 1 )
        {
            sum = 0;
            while( n != 0 )
            {
                sum += pow(n%10, 2);
                n = n/10;
            }
            if( record.find( sum ) == record.end() )
                record.insert( sum );
            else
                return false;
            n = sum; 
        }

        return true;
    }
};