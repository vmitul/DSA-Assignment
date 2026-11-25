#include <iostream>
#include <vector>

using namespace std;

// Find the Duplicate Number.
// https://leetcode.com/problems/find-the-duplicate-number/description/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = 0, f = 0;
        while ((s = nums[s]) != (f = nums[nums[f]]));
        s = 0;
        while ((s = nums[s]) != (f = nums[f]));
        return s;
    }

    int findDuplicate1(vector<int>& nums) {
        for (int x = 0; x < nums.size(); x++) {
            for (int y = x + 1; y < nums.size(); y++) {
                if (nums[x] == nums[y]) {
                    return nums[x];
                }
            }
        }
        return -1;
    }
};

int main(void) {
    vector<int> data = {1,3,4,2,5,2,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; // 2
    // vector<int> data = {3,3,3,3,3}; // 3
    // vector<int> data = {1,4,4,2,4}; // 4
    // vector<int> data = {0}; //

    Solution s{};
    cout << s.findDuplicate(data) << endl;

    return 0;
}
