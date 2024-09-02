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

// Solution in o(n/2)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        if (!head || !head->next)
            return head->next;

        if (fast->next) {
            fast = fast->next->next;
        }

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << slow->val << endl;
        if (slow && slow->next) {
            slow->next = slow->next->next;
        } else {
            slow->next = NULL;
        }

        return head;
    }
};