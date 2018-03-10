#include "ComonDef.h"

//https://leetcode.com/problems/median-of-two-sorted-arrays/description/

NAMESPACE_ANONYMOUS_BEGIN()

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = (int)nums1.size();
		int m = (int)nums2.size();
		if (n > m)   //保证数组1一定最短
			return findMedianSortedArrays(nums2, nums1);
		int L1, L2, R1, R2, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n长度
		while (lo <= hi)   //二分
		{
			c1 = (lo + hi) / 2;  //c1是二分的结果
			c2 = m + n - c1;
			L1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];   //map to original element
			R1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
			L2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
			R2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

			if (L1 > R2)
				hi = c1 - 1;
			else if (L2 > R1)
				lo = c1 + 1;
			else
				break;
		}
		return (max(L1, L2) + min(R1, R2)) / 2.0;
	}
};


NAMESPACE_ANONYMOUS_END()

void testFindMedianSortedArrays() {
	vector<int> nums1{1,2,3,4,5,6,7,8,9};
	vector<int> nums2{10,11,12,13,14,15,16,17,18,19,20,21,22,23};
	Solution sln;
	cout<<sln.findMedianSortedArrays(nums1, nums2) << endl;
}