#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0;
        int j = 0;
        double median;
        int middle;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] >= nums2[j])
            {
                merged.push_back(nums2[j]);
                j++;
            }
            else
            {
                merged.push_back(nums1[i]);
                i++;
            }
        }
        if (i != nums1.size())
            while(i < nums1.size())
            {
                merged.push_back(nums1[i]);
                i++;
            }
        else if (j != nums2.size())
            while (j != nums2.size())
            {
                merged.push_back(nums2[j]);
                j++;
            }
        middle = merged.size() / 2;
        if (merged.size() % 2 == 0)
            median = static_cast <double>((merged[middle] + merged[middle - 1])) / 2;
        else
            median = static_cast <double>(merged[middle]);
        return (median);
    }
};