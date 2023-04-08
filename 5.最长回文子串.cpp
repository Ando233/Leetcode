/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string preprocess(string s){
        int n = s.length();
        if (n == 0) {
            return "^$";
        }
        string ret = "^";
        for (int i = 0; i < n; i++){
            ret += "#";
            ret.append(1, s[i]);
        }
        ret += "#$";
        return ret;
    }

    string longestPalindrome(string s) {
        string t = preprocess(s);
        int n = t.length();
        vector<int> p(n, 0);
        int c = 0, r = 0;
        for (int i = 1; i < n - 1; i++) {
            int i_mirror = 2 * c - i;

            //  求出最小长度
            if (r > i) {
                p[i] = min(r - i, p[i_mirror]);// 防止超出 R
            }

            //  开始中心扩展
            while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
                p[i]++;
            }

            // 判断是否需要更新 R
            if (i + p[i] > r) {
                c = i;
                r = i + p[i];
            }

        }

        // 找出 P 的最大值
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < n - 1; i++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                centerIndex = i;
            }
        }
        int start = (centerIndex - maxLen) / 2; //最开始讲的求原字符串下标
        return s.substr(start, maxLen);
    }
};
// @lc code=end

