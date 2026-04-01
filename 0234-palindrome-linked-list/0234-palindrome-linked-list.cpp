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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        auto slow = head;
        auto fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        while (slow)
        {
            auto next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        auto left  = head;
        auto right = prev;

        while (right)
        {
            if (left->val != right->val) return false;
            left  = left->next;
            right = right->next;
        }

        return true;
    }
};