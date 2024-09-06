class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head, int x) {
        // Write your code here
        
        Node * temp = *head;
        
        while(temp){
            if(temp -> data == x){
                // check if the node being removed is the first node
                if(!temp -> prev && temp -> next){
                    Node * t = temp -> next;
                    temp -> next = NULL;
                    t -> prev = NULL;
                    temp = t;
                    // update head as after deattaching the head of the list we will need to
                    // update it other wise the linked list will be lost and we will just have the starting/head node
                    *head = t;
                }
                // check if the node being removed is the last node
                else if(temp -> prev && !temp -> next){
                    temp -> prev -> next = NULL;
                    temp -> prev = NULL;
                    break;
                }
                // check if the node is in the middle
                else if(temp -> prev && temp -> next){
                    Node * t = temp -> next;
                    // move the next pointer of the previous node of the current node to the next node of the current node
                    temp -> prev -> next = temp -> next;
                    // move the prev pointer of the next node of the current node to the prev node of the current node
                    temp -> next -> prev = temp -> prev;
                    // make the current pointer prev and null to deattach from the list
                    temp -> next = NULL;
                    temp -> prev = NULL;

                    // update current node
                    temp = t;
            // cout << temp -> data << " ";
                }
            }
            
            else{
                temp = temp -> next;
            }
        }
        
        // *head = temp;
        
        // cout << endl;
        
        
        
    }
};