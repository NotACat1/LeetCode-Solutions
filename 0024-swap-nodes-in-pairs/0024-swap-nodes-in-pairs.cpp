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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        auto dummy = new ListNode(0, head);
        auto prev = dummy;

        while (prev->next && prev->next->next) {
            auto first  = prev->next;
            auto second = prev->next->next;

            prev->next = second;
            first->next = second->next;
            second->next = first;

            prev = first;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};