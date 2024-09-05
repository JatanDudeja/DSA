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
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = head;
        ListNode* next = head->next;
        ListNode* temp = head;

        while (next) {
            prev = next;
            next = next->next;
            prev->next = temp;
            temp = prev;
        }

        head->next = NULL;

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        int cSum = 0;
        int carry = 0;

        while (l1 && l2) {
            cSum = l1->val + l2->val + carry;
            if (cSum > 9) {
                ListNode* t = new ListNode(cSum % 10);
                temp->next = t;
                carry = cSum / 10;
            } else {
                ListNode* t = new ListNode(cSum);
                temp->next = t;
                carry = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }

        while (l1) {
            cout << l1 -> val << endl;
            cSum = l1->val + carry;
            if (cSum > 9) {
                ListNode* t = new ListNode(cSum % 10);
                temp->next = t;
                carry = cSum / 10;
            } else {
                ListNode* t = new ListNode(cSum);
                temp->next = t;
                carry = 0;
            }

            temp = temp->next;
            l1 = l1->next;
        }

        while (l2) {
            cout << "in here in " << endl;
            cSum = l2->val + carry;
            if (cSum > 9) {
                ListNode* t = new ListNode(cSum % 10);
                temp->next = t;
                carry = cSum / 10;
            } else {
                ListNode* t = new ListNode(cSum);
                temp->next = t;
                carry = 0;
            }

            temp = temp->next;
            l2 = l2->next;
        }

        dummy = dummy->next;

        if (carry) {
            ListNode* finalReversedNode = reverseLL(dummy);
            ListNode* newNode = new ListNode(carry);
            newNode->next = finalReversedNode;
            temp = newNode;
            finalReversedNode = reverseLL(temp);
            return finalReversedNode;
        }

        return dummy;
    }
};