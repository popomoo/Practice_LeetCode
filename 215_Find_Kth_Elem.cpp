#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        QuickSort(nums);
        return nums[nums.size()-k];
    }

    void QuickSort( vector<int>& nums )
    {
        srand( time(NULL) );
        QSort( nums, 0, nums.size() - 1 );
    }

    void QSort( vector<int>& nums, int low, int high )
    {
        int lt = low;
        int gt = high + 1;
        int i = lt + 1;

        if( ( high - low ) <= 20 )
        {    
            InsertSort( nums, low, high );
            return;
        }

        swap( nums[low], nums[rand()%(high - low + 1) + low] );

        while( i < gt )
        {
            if( nums[i] < nums[low] )
                swap( nums[++lt], nums[i++] );
            else if( nums[i] > nums[low] )
                swap( nums[--gt], nums[i] );
            else
                i++;
        }
        swap( nums[lt], nums[low] );

        QSort( nums, low, lt - 1 );
        QSort( nums,  gt, high );

    }

    void InsertSort( vector<int>& nums, int low, int high )
    {
        for( int i = low + 1; i <= high; i++ )
        {
            if( nums[i] < nums[i-1] )
            {
                int temp = nums[i];
                int j;
                for( j = i-1; j >= low && nums[j] > temp; j-- )
                    nums[j+1] = nums[j];
                nums[j+1] = temp;
            }
        }
    }
};
