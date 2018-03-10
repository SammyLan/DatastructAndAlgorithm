#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "ComonDef.h"

using namespace std;


//https://leetcode.com/problems/two-sum/description/
NAMESPACE_ANONYMOUS_BEGIN()
class Solution {
public:
	vector<int> twoSum(vector<int> &num, int target) {
		return twoSumBySort(num, target);
	}

	vector<int> twoSumByMap(vector<int> &num, int target) {
		unordered_map<int, int> mapping;
		vector<int> result;
		for (int i = 0; i < (int)num.size(); i++) {
			mapping[num[i]] = i;
		}
		for (int i = 0; i < (int)num.size(); i++) {
			const int gap = target - num[i];
			unordered_map<int, int>::iterator it = mapping.find(gap);
			if (it != mapping.end() && it->second != i) {
				result.push_back(i);
				result.push_back(it->second);
				break;
			}
		}
		return result;
	}

	vector<int> twoSumBySort(vector<int> &num, int target) {
		vector<pair<int, int>>  tmp(num.size());
		for (size_t i = 0; i < num.size(); i++) {
			tmp[i].first = num[i];
			tmp[i].second = (int)i;
		}
		//ÅÅÐò
		std::sort(tmp.begin(), tmp.end(), [](const pair<int, int> & a, const pair<int, int> & b) -> bool {
			return a.first < b.first;
		});

		for (auto item : tmp) {
			int val = target - item.first;
			auto it = std::lower_bound(tmp.begin(),tmp.end(),std::make_pair(val,0), [](const pair<int, int> & a, const pair<int, int> & b) -> bool {
				return a.first < b.first;
			});
			if (it != tmp.end() && it->first == val) {
				while (it->second == item.second) {
					++it;
				}
				return vector<int>({ std::min(it->second,item.second), std::max(it->second, item.second) });
			}
		}
		return vector<int>({ -1,-1 });
	}

};
NAMESPACE_ANONYMOUS_END()

void testTwoSum() {
	vector<int> num{ -3,4,3,90 };
	int target = 0;
	Solution sln;
	auto ret = sln.twoSum(num, target);
	ostream_iterator<int> output(cout, " ");
	copy(ret.begin(), ret.end(), output);
}