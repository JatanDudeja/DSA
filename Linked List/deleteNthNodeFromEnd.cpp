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
        ListNode * slow = head, *fast = head;

        while(n > 0){
            if(!fast) break;
            fast = fast -> next;
        // cout << fast -> val;
            n--;
        }

        if(!fast){
            slow = slow -> next;
            head = slow;
            return head;
        }


        while(fast -> next){
            slow = slow -> next;
            fast = fast -> next;
        }

        cout << slow -> val;
        // if(slow -> next)
            slow -> next = slow -> next -> next;
        // else{
        //     slow = NULL;
        // }


        return head;
    }
};