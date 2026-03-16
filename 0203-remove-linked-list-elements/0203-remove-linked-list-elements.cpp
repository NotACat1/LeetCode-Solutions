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
    ListNode* removeElements(ListNode* head, int val) {
        auto dummy = new ListNode(0);
        dummy->next = head;

        auto current = dummy;

        while (current->next) {
            auto nextNode = current->next;

            if (nextNode->val == val) {
                current->next = nextNode->next;
                delete nextNode;
            }
            else {
                current = nextNode;
            }
        }

        auto result = dummy->next;
        delete dummy;

        return result;
    }
};