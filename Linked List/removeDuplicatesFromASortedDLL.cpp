class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        Node * temp = head;
        Node * curr = head;
        // cout << 1111<< endl;
        while(curr && curr -> next){
            // cout << " in" << endl;
            if(curr -> data == curr -> next -> data){
                temp = curr -> next;
                    if(curr -> prev){
                        curr -> prev -> next = curr -> next;
                        curr -> next -> prev = curr -> prev;
                        curr -> prev = NULL;
                        curr -> next = NULL;
                    
                    }
                    else{
                        // cout << curr -> data << " " << curr -> prev -> data << " " << curr -> next -> data << endl;;
                        head = curr -> next;
                        curr -> next = NULL;
                        temp -> prev = NULL;
                    }
                    
                    curr = temp;
                    temp = temp -> next;
                
            }
            else{
                curr = curr -> next;
            }
        }
        
        return head;
    }
};