class Solution {
  public:
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        
        Node * p = head, *n = head -> next, *temp = head;
        int carry = 0;
        
        // reverse the list to start add from the end
        while(n){
            p = n;
            n = n -> next;
            p -> next = temp;
            temp = p;
        }
        
        // make the next of head as null, that was the starting of the LL but now is last Node
        head -> next = NULL;
        
        temp = p;
        
        // add 1 now to the first node that is actually the last node given in the LL/question
        int add = temp -> data + 1;
        
        
        // save the last digit of the addition
        temp -> data = add % 10;
        
        // make carry 1 if sum > 9
        if(add > 9){
            carry = 1;
        }
        
        // move to the next node
        temp = temp -> next;
        
        while(temp){
            // get sum of the current node and carry if there is any
            add = temp -> data + carry;
            
            // if greater than 9 then just store the last digit of the sum and save 1 as carry
            if(add > 9){
                temp -> data = add % 10;
            }
            // else just save the number and make carry 0 and break the look
            /*
            we are making carry as 0 because
            if at the end we still have 1 as
            carry then we will create a new
            node and attach the ll after
            adding 1 to this carry node
            
            For eg: 99
            at the end we will have 00 as output and we will still
            have 1 from which we will make 1 more node and attach 00
            1 which will result in 1 -> 0 -> 0 as the final result.
            */
            else{
                temp -> data = add;
                carry = 0;
                break;
            }
            
            temp = temp -> next;
            
        }
            
        // again reverse the linked list after adding one as we were
        // adding from the last
        n = p -> next;
        temp = p;
        
        p -> next = NULL;
        
        while(n){
            p = n;
            n = n -> next;
            p -> next = temp;
            temp = p;
        }
        
        
        /*
        After revering check if there is any carry available if yes then
        create a node and attach the remaing list to it
        */
        if(carry){
            Node * newNode = new Node(carry);
            newNode -> next = p;
            p = newNode;
        }
        
        
        // return p
        return p;
    }
};