#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        HeapSort(nums);
        return nums[nums.size() - k];
    }

    void HeapSort( vector<int>& nums )
    {
        for( int i = nums.size()/2 - 1; i >= 0; i-- )
            HeapAdjust( nums, i, nums.size() );
        
        for( int i = nums.size() - 1; i > 0; i-- )
        {
            swap( nums[0], nums[i] );
            HeapAdjust( nums, 0, i - 1 );
        }
    }

    void HeapAdjust( vector<int>& nums, int summit, int end )
    {
        int temp = nums[summit];
        int j;

        for( j = 2*summit + 1; j < end; j = j*2 + 1 )
        {
            if( j + 1 < end && nums[j] < nums[j+1] )
                j++;

            if( j < end && nums[j] <= temp )
                break;
            
            nums[summit] = nums[j];
            summit = j;
        }
        nums[summit] = temp;
    }
};