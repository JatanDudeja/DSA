/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        int count = 0;
        int l1 = 0;
        int l2 = 0;

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while (tempA) {
            l1++;
            tempA = tempA->next;
        }

        while (tempB) {
            l2++;
            tempB = tempB->next;
        }

        int lengthDiff = l1 > l2 ? l1 - l2 : l2 - l1;

        ListNode* smallLenghtHead = l1 > l2 ? headB : headA;
        ListNode* bigLengthHead = l1 > l2 ? headA : headB;

        /*
            Point to note :-
            1. When the lenght of both the LL is
            same then the intersection will fall
            at same place only i.e. we can both the
            small and large heads equally otherwise
            we only move big head until we have passed
            all the nodes and have reached the same
            length as of the small head LL.
        */
        
        while (smallLenghtHead && bigLengthHead) {
            if (smallLenghtHead != bigLengthHead) {
                if (count < lengthDiff) {
                    count++;
                    bigLengthHead = bigLengthHead->next;
                    continue;
                }
            } else {
                return smallLenghtHead;
            }

            smallLenghtHead = smallLenghtHead->next;
            bigLengthHead = bigLengthHead->next;
        }

        return NULL;
    }
};