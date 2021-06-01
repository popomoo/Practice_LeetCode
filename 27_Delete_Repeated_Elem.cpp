#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i;
        int k = 0;

        for( i = 1; i < nums.size(); i++ )
        {
            if( nums[i] != nums[k] )
            {
                if( i != k + 1 )
                    swap( nums[k+1], nums[i] );
                k++;
            }
        }
        
        if( nums.size() == 0 )
            return 0;
        else
            return k + 1;
    }
};