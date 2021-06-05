#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int l = 0;
        int r = -1;
        int sum = 0;
        int res = nums.size() + 1;

        while ( l < nums.size() )
        {
            if( r + 1 < nums.size() && sum < target )
                sum += nums[++r];
            else
                sum -= nums[l++];

            if( sum >= target )
                res = min(res, r - l + 1);
        }

        if( res == nums.size() + 1 )
            return 0;
        else
            return res;
    }
};