class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node * traverseNodes(Node * head1, Node* head2){
        Node * dummy = new Node(0);
        Node * temp = dummy;
        while(head1 && head2){
            if(head1 -> data < head2 -> data){
                Node * t = new Node(head1 -> data);
                temp -> bottom = t;
                temp = temp -> bottom;
                head1 = head1 -> bottom;
                // delete temp;
            }
            else{
                Node * t = new Node(head2 -> data);
                temp -> bottom = t;
                temp = temp -> bottom;
                head2 = head2 -> bottom;
                // delete temp;
            }
        }
        
        if(head1){
            temp -> bottom = head1;
        }
        if(head2){
            temp  -> bottom = head2;
        }
        
        return dummy -> bottom;
    }
    
    Node * flattenLL(Node * head){
         if(!head || !head -> next){
            return head;
        }
        
        // move to the very last node get the last node and then use the traverseNode function
        // to sort and merge the current head and the mergedNode
        Node * mergedNode = flattenLL(head -> next);
        
        // head will be the current node and mergedNode will be the
        // merged node or the last node of the LL when the function reaches
        // base case
        return traverseNodes(head, mergedNode);
    }
    
    Node *flatten(Node *root) {
        // Your code here
        if(!root || !root -> next){
            return root;
        }
        
        return flattenLL(root);
    }
};
