#include "ComonDef.h"

//https://leetcode.com/problems/search-a-2d-matrix/description/

NAMESPACE_ANONYMOUS_BEGIN()
class Solution {
public:
	bool searchMatrix(const vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) {
			return false;
		}
		int row = matrix.size();
		int col = matrix[0].size();
		int i = 0;
		int j = col - 1;
		while (i < row && j >= 0) {
			if (matrix[i][j] == target) {
				return true;
			}
			if (matrix[i][j] > target) {
				--j;
			} else {
				++i;
			}
		}

		return false;
	}
};
NAMESPACE_ANONYMOUS_END();

void testSearcha2DMatrix(){
	Solution sln;
	cout << sln.searchMatrix({ {1,4}, {2,5} },2) << endl;;
}