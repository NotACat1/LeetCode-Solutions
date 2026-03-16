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
        auto current = &head;

        while (*current) {
            if ((*current)->val == val) {
                auto temp = *current;
                *current = (*current)->next;
                delete temp;
            }
            else{
                current = &((*current)->next);
            }
        }

        return head;
    }
};
