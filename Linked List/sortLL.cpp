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
    ListNode* getMid(ListNode* head) {
        ListNode *slow = head, *fast = head;

        if (fast && fast->next) {
            fast = fast->next->next;
        }

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* getHeadOfMergedLL(ListNode* leftHead, ListNode* rightHead) {
        ListNode* mergedHead = new ListNode(0);
        ListNode* mergedTail = mergedHead;

        while (leftHead && rightHead) {
            if (leftHead->val < rightHead->val) {
                mergedTail->next = leftHead;
                leftHead = leftHead->next;

            } else {
                mergedTail->next = rightHead;
                rightHead = rightHead->next;
            }
            mergedTail = mergedTail->next;
        }

        if (leftHead) {
            mergedTail->next = leftHead;
        } else {
            mergedTail->next = rightHead;
        }

        return mergedHead->next;
    }

    ListNode* sorting(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* mid = getMid(head); // get mid
        // cout << mid -> val << " ";
        ListNode* nextToMid = mid->next; // get next element to mid
        mid->next =
            NULL; // make the next pointer of mid node to null to break before
                  // and after middle nodes in into right and left parts

        // sort left half i.e. till mid
        ListNode* sortLeft = sorting(head);

        // sort right half i.e. after mid
        ListNode* sortRight = sorting(nextToMid);

        // merge both the sorted halves
        ListNode* headOfMergedLL = getHeadOfMergedLL(sortLeft, sortRight);

        return headOfMergedLL;
    }

    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;

        if (!head || !head->next)
            return head;

        ListNode* ans = sorting(temp);

        return ans;
    }
};