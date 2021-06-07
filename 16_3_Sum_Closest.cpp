#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int res = 0;
        if( nums.size() < 3 )
            return res;

        sort( nums.begin(), nums.end() );
        res = nums[0] + nums[1] + nums[nums.size() - 1];

        for( int i = 0; i < nums.size() - 2; i++ )
        {
            if( i > 0 && nums[i] == nums[i - 1] )
                continue;
            int left = i + 1;
            int right = nums.size() - 1;

            while( left < right )
            {
                
                if( abs(nums[i] + nums[left] + nums[right] - target) < abs(res - target) )
                    res = nums[i] + nums[left] + nums[right];

                if( nums[i] + nums[left] + nums[right] > target )
                {
                    right--;
                    while( right > left && nums[right] == nums[right + 1] )
                        right--;
                }
                else if( nums[i] + nums[left] + nums[right] < target  )
                {
                    left++;
                    while( left < right && nums[left] == nums[left - 1] )
                        left++;
                }
                else
                    return target;
            }
        }
        return res;
    }
};