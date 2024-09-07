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

// My best solutions - the TC of both the solutions
// is almost same so not much difference but the code
// below my solution is
// better written and has one less loop

// My Solution
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode * temp = head;

        int length = 0;

        if(k == 0 || !head || !head -> next){
            return head;
        }

        // get the length of the Linked List
        while(temp) {
            temp = temp -> next;
            length++;
        }

        temp = head;

        // get the length of the nodes that we want to leave from the starting
        // and then get the remaining nodes and join them to the given head of the Linked List
        k = length - (k % length);

        // subtract 1 as we are already standing on one of the node
        k--;

        // get kth Node
        while(k > 0){
            temp = temp -> next;
            k--;
        }

        // cout << temp -> val << endl;

        ListNode * next = NULL;

        if(!temp -> next){
            return head;
        }

        // store the next of the kthNode if not NULL 
        next = temp -> next;
        // cout << next -> val << endl;

        temp -> next = NULL;

        // cout << temp -> val << endl;

        temp = next;

        // get the last node of the nodes after length - k to join them to the given head
        while(temp -> next){
            temp = temp -> next;
        }

        cout << temp -> val << endl;

        // join
        temp -> next = head;

        // update the head
        head = next;

        return head;
    }
};






// Best Solution
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        // calculating length
        ListNode* temp = head;
        int length = 1;
        while (temp->next != NULL) {
            ++length;
            temp = temp->next;
        }
        // link last node to first node
        temp->next = head;
        k = k % length;       // when k is more than length of list
        int end = length - k; // to get end of the list
        while (end--)
            temp = temp->next;
        // breaking last node link and pointing to NULL
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};
