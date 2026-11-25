#include <iostream>
#include <vector>

using namespace std;

// Next Greater Element.
// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        vector<int> r(arr.size(), -1);
        for (int x = 0; x < arr.size()-1; x++) {
            for (int y = x + 1; y < arr.size(); y++) {
                if (arr[y] > arr[x]) {
                    r[x] = arr[y]; break;
                }
            }
        }
        return r;
    }
    // vector<int> nextLargerElement(vector<int>& arr) {
    //     stack<int> s{};
    //     vector<int> r(arr.size(), -1);
    //     for (int x = arr.size()-1; x >= 0; x--) {
    //         while (!s.empty() && s.top() <= arr[x]) { s.pop(); }
    //         if (!s.empty()) { r[x] = s.top(); }
    //         s.push(arr[x]);
    //     }
    //     return r;
    // }
};

int main(void) {
    vector<int> data = {11,18,20,11,10,15,16,4,19,6,1}; // [18,20,-1,15,15,16,19,19,-1,-1,-1]
    // vector<int> data = {6,8,0,1,3}; // [8,-1,1,3,-1]
    // vector<int> data = {1,3,2,4}; // [3,4,4,-1]

    Solution s{};
    vector<int> r = s.nextLargerElement(data);
    for (int n : r) cout << n << " "; cout << endl;

    return 0;
}
