#include "ComonDef.h"

//https://leetcode.com/problems/search-a-2d-matrix/description/

NAMESPACE_ANONYMOUS_BEGIN()
class Solution {
public:
	bool searchMatrix(const vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) {
			return false;
		}
		size_t const m = matrix.size();
		size_t const n = matrix.front().size();
		int low = 0;
		int hi = m * n;
		while (low < hi) {
			int mid = (low + hi) / 2;
			int i = mid / n;
			int j = mid % n;
			int val = matrix[i][j];
			if (val == target ) {
				return true;
			}
			if (val < target) {
				low = mid + 1;
			} else {
				hi = mid;
			}
		}
		return false;
	}
};
NAMESPACE_ANONYMOUS_END();