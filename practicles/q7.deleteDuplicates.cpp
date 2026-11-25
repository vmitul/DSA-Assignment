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

// Remove Duplicates from Sorted List.
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *tmp = head->next;
        ListNode *nav = head;
        ListNode *res = nav;
        while (tmp) {
            if (nav->val != tmp->val) {
                nav->next = tmp;
                nav = nav->next;
            }
            tmp = tmp->next;
        }
        nav->next = nullptr;
        return res;
    }
};

int main(void) {
    Solution s{};
    vector<int> nums = {1,2,2,3,4,4,5,6,6};
    ListNode *head = nullptr, *tmp = nullptr;

    for (int n : nums) {
        if (head == nullptr) {
            tmp = head = new ListNode(n);
            continue;
        }
        tmp->next = new ListNode(n);
        tmp = tmp->next;
    }

    ListNode *unique = s.deleteDuplicates(head);
    while (unique) {
        cout << unique->val << " ";
        unique = unique->next;
    }
    cout << endl;

    return 0;
}
