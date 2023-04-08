/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int k = (len1 + len2) >> 1;
        if((len1 + len2) & 1){
            return find_kth_element(nums1, nums2, k + 1) * 1.0;
        }
        else{
            return (find_kth_element(nums1, nums2, k + 1) + find_kth_element(nums1, nums2, k)) / 2.0;
        }
    }

    double find_kth_element(vector<int>& nums1, vector<int>& nums2, int k){
        int len1 = nums1.size(), len2 = nums2.size();
        int index1 = 0, index2 = 0;
        while (true){
            if(index1 == len1){
                return nums2[index2 + k - 1];
            }
            if(index2 == len2){
                return nums1[index1 + k - 1];
            }
            if(k == 1){
                return min(nums1[index1], nums2[index2]);
            }
            int new_index1 = min(index1 + k/2 - 1, len1 - 1);
            int new_index2 = min(index2 + k/2 - 1, len2 - 1);
            if(nums1[new_index1] <= nums2[new_index2]){
                k -= (new_index1 - index1 + 1);
                index1 = new_index1 + 1;
            }
            else {
                k -= (new_index2 - index2 + 1);
                index2 = new_index2 + 1;
            }
        }

    }
};
// @lc code=end

