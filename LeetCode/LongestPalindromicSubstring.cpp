#include "ComonDef.h"

//https://leetcode.com/problems/median-of-two-sorted-arrays/description/

//p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;

NAMESPACE_ANONYMOUS_BEGIN()

class Solution {
public:
	string adjustString(string const & str) {
		string strNew = "$#";
		size_t size = str.size();
		for (size_t i = 0; i < size; ++i) {
			strNew += str[i];
			strNew += '#';
		}
		return strNew;
	}
	string longestPalindrome(string s) {
		string strNew = adjustString(s);
		int rightest = 0; //回文串能延伸到的最右端的位置
		int center = 0; //最大回文子串中心的位置

		int maxCenter = 0;
		int maxLen = 0;
		int size = (int)strNew.size();
		vector<int> dp(size);
		for (int i = 1; i < size; i++) {
			dp[i] = rightest > i ? min(dp[2 * center - i], rightest - i) : 1;
			while (strNew[i + dp[i]] == strNew[i - dp[i]]) {
				dp[i]++;
			}
			if (i + dp[i] > rightest) {
				rightest = i + dp[i];
				center = i;
			}
			if (maxLen < dp[i]) {
				maxLen = dp[i];
				maxCenter = i;
			}
		}
		return s.substr((maxCenter - maxLen) / 2, maxLen - 1);
	}
};

NAMESPACE_ANONYMOUS_END()