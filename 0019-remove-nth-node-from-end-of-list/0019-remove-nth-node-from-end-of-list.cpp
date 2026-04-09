/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(0, head);
        auto fast = dummy;
        auto slow = dummy;

        for (size_t i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }

        auto nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        auto newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};