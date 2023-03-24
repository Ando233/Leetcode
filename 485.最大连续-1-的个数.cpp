/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = nums[0];
        int len = nums.size();
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        for(int i = 1; i < len; i++){
            dp[i] = nums[i] == 1 ? dp[i - 1] + 1 : 0;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

