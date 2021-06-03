#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int l = 0;
        int r = height.size() - 1;
        int area;
        int max = 0;

        while( l < r )
        {
            if( height[l] <= height[r] )
            {
                area = (r - l)*height[l];
                l++;
            }
            else
            {
                area = (r - l)*height[r];
                r--;
            }
            max = ( area > max ) ? area : max;
        }
        return max;
    }
};