#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int tail = nums1.size();
        int i = m - 1;
        int j = n - 1;

        while( tail > 0 )
        {
            if( j < 0 )
                nums1[--tail] = nums1[i--];
            else if( i < 0 )
                nums1[--tail] = nums2[j--];
            else if( nums1[i] > nums2[j] )
                nums1[--tail] = nums1[i--];
            else
                nums1[--tail] = nums2[j--];
        }
    }
};