#include "ComonDef.h"

//https://leetcode.com/problems/reverse-integer/description/

NAMESPACE_ANONYMOUS_BEGIN()

class Solution {
public:
	int reverse(int x) {
		long long int result = 0;
		while (x != 0) {
			result *= 10;
			result += x % 10;
			x /= 10;
		}
		return (result < INT_MIN || result > INT_MAX) ? 0 : result;
	}
};

NAMESPACE_ANONYMOUS_END()

void testReverseInteger() {
	int val;
	cin >> val;
	Solution sln;
	cout << sln.reverse(val);
}
