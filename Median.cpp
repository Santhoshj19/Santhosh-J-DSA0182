#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        swap(nums1, nums2);
    }

    int m = nums1.size();
    int n = nums2.size();
    int left = 0, right = m;
    int halfLen = (m + n + 1) / 2;

    while (left <= right) {
        int i = (left + right) / 2;
        int j = halfLen - i;
        
        if (i < m && nums2[j - 1] > nums1[i]) {
            left = i + 1;
        } else if (i > 0 && nums1[i - 1] > nums2[j]) {
            right = i - 1;
        } else {
            int maxLeft = 0;
            if (i == 0) {
                maxLeft = nums2[j - 1];
            } else if (j == 0) {
                maxLeft = nums1[i - 1];
            } else {
                maxLeft = max(nums1[i - 1], nums2[j - 1]);
            }
            
            if ((m + n) % 2 == 1) {
                return maxLeft;
            }
            
            int minRight = 0;
            if (i == m) {
                minRight = nums2[j];
            } else if (j == n) {
                minRight = nums1[i];
            } else {
                minRight = min(nums1[i], nums2[j]);
            }
            
            return (maxLeft + minRight) / 2.0;
        }
    }
    
    return 0.0;
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl;
    
    return 0;
}