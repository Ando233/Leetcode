/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)){
            return false;
        }
        int x_reverse = 0;
        while (x > x_reverse){
            x_reverse *= 10;
            x_reverse += x % 10;
            x /= 10;
        }
        return x == x_reverse || x == x_reverse / 10;
    }
};
// @lc code=end

