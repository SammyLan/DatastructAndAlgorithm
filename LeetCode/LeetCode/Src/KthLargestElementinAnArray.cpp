//
//  KthLargestElementinAnArray.cpp
//  LeetCode
//
//  Created by 蓝秀文 on 2018/11/10.
//  Copyright © 2018 蓝秀文. All rights reserved.
//

//https://leetcode.com/problems/kth-largest-element-in-an-array/
#include "KthLargestElementinAnArray.hpp"
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,std::vector<int>,std::greater<int> > queue;
        for (int i = 0; i < k; ++i) {
            queue.push(nums[i]);
        }
        for (int i = k ; i < nums.size(); ++i) {
            int val = nums[i];

            if (val > queue.top()) {
                queue.pop();
                queue.push(val);
            }
        }
        return queue.top();
    }
};
