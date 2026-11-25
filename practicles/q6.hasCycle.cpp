#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Detect a node in linked list.
// https://leetcode.com/problems/linked-list-cycle/description/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode *s = head, *f = head;
        while (f && f->next) {
            if (f->next == s) return true;
            s = s->next;
            f = f->next->next;
        }
        return false;
    }
};

int main(void) {
    Solution s{};
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    ListNode *head = nullptr, *tmp = nullptr;

    for (int n : nums) {
        if (head == nullptr) {
            tmp = head = new ListNode(n);
            continue;
        }
        tmp->next = new ListNode(n);
        tmp = tmp->next;
    }

    tmp->next = head; // create a cycle

    cout << s.hasCycle(head) << endl;

    return 0;
}
