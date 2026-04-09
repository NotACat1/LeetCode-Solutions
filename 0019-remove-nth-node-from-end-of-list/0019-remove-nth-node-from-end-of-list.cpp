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
        size_t size = 0;
        auto current = head;
        while (current) {
            size++;
            current = current->next;
        }

        auto dummy = new ListNode(0, head);
        auto pred = dummy;

        for (int i = 0; i < size - n; i++) {
            pred = pred->next;
        }

        auto toDelete = pred->next;
        pred->next = pred->next->next;

        delete toDelete;

        auto newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};