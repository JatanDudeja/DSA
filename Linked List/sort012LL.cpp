class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        
        if(!head || !head -> next){
            return head;
        }
        
        Node * zeroHead = new Node(0);
        Node * oneHead = new Node(1);
        Node * twoHead = new Node(2);
        Node * zeroTail = zeroHead;
         Node * oneTail = oneHead;
          Node * twoTail = twoHead;
        
        while(head){
            Node* tempNode = new Node(head -> data);
            if(head -> data == 0){
                zeroTail -> next = tempNode;
                zeroTail = zeroTail -> next;
            }
            else if(head -> data == 1){
                oneTail -> next = tempNode;
                oneTail = oneTail -> next;
            }
            else{
                twoTail -> next = tempNode;
                twoTail =twoTail -> next;
            }
            
            head = head -> next;
        }
        
        // cout << zeroHead -> next -> data << endl;
        // cout << oneHead -> next -> data << endl;
        // cout << twoHead -> next -> next -> data << endl;
        oneHead = oneHead -> next;
        twoHead = twoHead -> next;
        
        
        if(oneHead){
            zeroTail -> next = oneHead;
        }
        
        if(twoHead){
            // cout << twoHead -> data << endl;
            if(oneHead){
                // cout << " in twoHead if "<< oneTail -> data << endl;
            oneTail -> next = twoHead;
            }
            else{
                // cout << " in twoHead else "<< zeroTail -> data << endl;
            zeroTail -> next = twoHead;
                
            }
        }
        
        zeroHead = zeroHead -> next;
        
        return zeroHead;
    }
};