#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Find the middle element.
// https://leetcode.com/problems/middle-of-the-linked-list/description/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode *tmp = head;
        while ((tmp = tmp->next)) len++;
        len = (len + 1) / 2;
        tmp = head;
        while (len--) tmp = tmp->next;
        return tmp;
    }
};

int main(void) {
    Solution s{};
    vector<int> nums = {1,2,3,4,5,6};
    ListNode *head = nullptr, *tmp = nullptr;

    for (int n : nums) {
        if (head == nullptr) {
            tmp = head = new ListNode(n);
            continue;
        }
        tmp->next = new ListNode(n);
        tmp = tmp->next;
    }

    ListNode* subList = s.middleNode(head);
    do cout << subList->val << " ";
    while ((subList = subList->next));
    cout << endl;

    return 0;
}
