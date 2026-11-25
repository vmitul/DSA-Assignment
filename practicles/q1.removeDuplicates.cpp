#include <iostream>
#include <vector>

using namespace std;

// Remove Duplicates from Sorted Array.
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int x = 0; // Unique element index.
        for (int y = 1; y < nums.size(); y++) {
            if (nums.at(x) == nums.at(y)) {
                continue;
            }
            nums[++x] = nums.at(y);
        }
        // Since x is 0-based index, we need
        // to add one to treat it as real length.
        return x + 1;
    }
};

int main(void) {
    // Sample test data with 5 unique elements.
    vector<int> data = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    Solution s{};
    cout << s.removeDuplicates(data) << endl;

    return 0;
}
