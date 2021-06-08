#include <climits>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        set<int> record;
        for( int i = 0; i < nums.size(); i++ )
        {
            if( record.lower_bound( max(nums[i], INT_MIN + t) - t ) != record.end() && *record.lower_bound( max(nums[i], INT_MIN + t ) - t ) <= min(nums[i], INT_MAX - t) + t )
                return true;
            else
                record.insert( nums[i] );

            if( record.size() == k + 1 )
                record.erase( nums[i - k] );
        }
        return false;
    }
};