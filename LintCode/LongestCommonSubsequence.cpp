#include "ComonDef.h"

//http://lintcode.com/zh-cn/problem/longest-common-subsequence/

NAMESPACE_ANONYMOUS_BEGIN()

class Solution {
public:
	/**
	* @param A: A string
	* @param B: A string
	* @return: The length of longest common subsequence of A and B
	*/
	/*

	*/
	int longestCommonSubsequence(string const&A, string const&B) {
		if (A.size() < B.size()) {
			return longestCommonSubsequenceImpl(A, B);
		}
		return longestCommonSubsequenceImpl(B, A);
	}
private:
	int longestCommonSubsequenceImpl(string const&A, string const&B) {
		/*
		dp[i,j] = 0;				(i == 0 or j == 0)
				= dp[i-1][j-1];		(i > 0  and j > 0 && A[i-1] == B[i-1])
				= max(dp[i,j-1],dp[i-1,j);		(i > 0  and j > 0 && A[i-1] != B[i-1])
		*/
		vector<int> dp0(A.size() + 1);
		vector<int> dp1(B.size() + 1);
		vector<int> * pDp0 = &dp0;
		vector<int> * pDp1= &dp1;
		int lcs = 0;
		for (size_t i = 1; i <= A.size(); i++) {
			vector<int> & rDp0 = * pDp0;
			vector<int> & rDp1 = * pDp1;

			for (size_t j = 1; j <= B.size(); j++) {
				if (A[i - 1] == B[j -1]) {
					rDp1[j] = rDp0[j - 1] + 1;
				} else {
					rDp1[j] = max(rDp0[j ],rDp1[j-1]);
				}
				lcs = max(lcs, rDp1[j]);
			}
			swap(pDp0, pDp1);
		}
		return lcs;
	}
};
NAMESPACE_ANONYMOUS_END()

void testLongestCommonSubsequence() {
	Solution sln;
	
	cout << sln.longestCommonSubsequence("bedaacbade", "dccaeedbeb");
}