#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> res;
        if( nums.size() < 4 )
            return res;
        
        sort( nums.begin(), nums.end() );

        for( int i = 0; i < nums.size() - 3; i++ )
        {
            if( i > 0 && nums[i] == nums[i-1] )
                continue;

            if( nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target )
                break;
            if( nums[i] + nums[nums.size()-3] + nums[nums.size()-2] + nums[nums.size()-1] < target )
                continue;

            for( int j = i + 1; j < nums.size() - 2; j++ )
            {
                if( j > i + 1 && nums[j] == nums[j - 1] )
                    continue;
                
                if( nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target )
                    break;
                if( nums[i] + nums[j] + nums[nums.size()-2] + nums[nums.size()-1] < target )
                    continue;
                
                int left = j + 1;
                int right = nums.size() - 1;

                while( left < right )
                {
                    if( nums[left] + nums[right] + nums[i] + nums[j] == target )
                    {
                        res.push_back( vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while( left < right && nums[left] == nums[left - 1] )
                            left++;
                        while( left < right && nums[right] == nums[right + 1] )
                            right--;
                    }
                    else if( nums[left] + nums[right] + nums[i] + nums[j] < target )
                        left++;
                    else
                        right--;
                }
            }
        }
        return res;
    }
};