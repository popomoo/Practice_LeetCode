#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        if( nums.size() < 3 )
            return  res;
            
        sort( nums.begin(), nums.end() );

        for( int i = 0; i < nums.size() - 2 ; i++ )
        {
            if( nums[i] > 0 )
                break;

            if( i > 0 && nums[i] == nums[i - 1] )
                continue;
            
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            while( left < right )
            {
                if( nums[left] + nums[right] == target )
                {
                    res.push_back( vector<int>{nums[i], nums[left], nums[right]} );
                    left++;
                    right--;

                    while( left < right && nums[left] == nums[left - 1] )
                        left++;
                    while( left < right && nums[right] == nums[ right + 1 ] )
                        right--;
                }
                else if( nums[left] + nums[right] < target )
                    left++;
                else
                    right--;
            }
        }

        return res;
    }
};