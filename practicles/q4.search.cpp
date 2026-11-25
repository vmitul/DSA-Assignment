#include <iostream>
#include <vector>

using namespace std;

// Binary Search.
// https://leetcode.com/problems/binary-search/description/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int l = 0, h = nums.size() - 1; l <= h;) {
            int m = l + (h - l) / 2;
            if (target == nums.at(m)) return m;
            target < nums.at(m) ? (h = m - 1) : (l = m + 1);
        }
        return -1;
    }
};

int main(void) {
    vector<int> nums1 = {-1,0,3,5,9,12}; int target1 = 9;
    vector<int> nums2 = {-1,0,3,5,9,12}; int target2 = 2;

    Solution s{};
    cout << s.search(nums1, target1) << endl;
    cout << s.search(nums2, target2) << endl;

    return 0;
}
