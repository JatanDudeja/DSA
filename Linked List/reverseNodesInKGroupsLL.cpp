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
    ListNode* reverseLL(ListNode* s) {
        ListNode* current = s;
        ListNode* prev = NULL;
        ListNode* next = s->next;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        // s->next = NULL;

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* next = NULL;
        ListNode* ans = NULL;
        ListNode* reversed = NULL;

        while (current) {
            int count = k;
            ListNode* kthNode = current;

            // get the kth node
            while (kthNode && count > 1) {
                kthNode = kthNode->next;
                count--;
            }

            // if no kth node that means there are less number of nodes present than k
            // in that case we just break from the loop
            if (kthNode == NULL) {
                // if prev is present that is current is not the head
                // in this case we have to attach the prev node to the current node
                if (prev)
                    prev->next = current;
                // and then break
                break;
            }

            // store the kth node
            next = kthNode->next;

            // make the next pointer of the kth node to point at NULL
            kthNode->next = NULL;

            // reverse the nodes from current node to kth node i.e. the k number of nodes
            reversed = reverseLL(current);

            // if current == head it means we need to store that as it will
            // be out new head
            if (current == head) {
                ans = reversed;
            } else {
                // join the linked list
                prev->next = reversed;
            }
            prev = current;
            current = next;
        }

        return ans;
    }
};