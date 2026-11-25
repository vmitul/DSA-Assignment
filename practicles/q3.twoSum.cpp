#include <iostream>
#include <vector>

using namespace std;

// Two Sum.
// https://leetcode.com/problems/two-sum/description/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int x = 0; x < nums.size(); x++) {
            for (int y = x + 1; y < nums.size(); y++) {
                if (nums.at(x) + nums.at(y) == target) {
                    return {x, y};
                }
            }
        }
        return {-1, -1};
    }
};

int main(void) {
    vector<int> nums = {2, 7, 11, 15}; int target = 9;
    // vector<int> nums = {3, 2, 3, 7}; int target = 6;

    Solution s{};
    vector<int> r =  s.twoSum(nums, target);
    cout << nums.at(r.front())
         << " + " << nums.at(r.back())
         << " = " << target << endl;

    return 0;
}
