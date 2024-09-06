class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int, int>> ans;
        
        if(!head || head -> next == NULL){
            return ans;
        }
        
        // take start pointer
        Node *s = head;
        Node * temp= head -> next;

        // take end pointer that will point to the end of the DLL when the first while loop runs 
        Node* e = head;
        
        while(temp){
            // cout << e -> data << endl;
            temp = temp -> next;
            e = e -> next;
        }

        // now after above loop e points to the end of the DLL
        
        // cout << e -> data << endl;
        
        int sum = 0;
        
        while(s != e){
            sum = s -> data + e -> data;
            // if sum == target just push the data of the nodes and move both the points s and e (s to s->next and e to e->prev)
            if(sum == target){
            // cout << s -> prev << " " << e -> next << endl;
            // if s -> prev and e -> next exists this means
            // that both s and e are not at the starting and ending nodes of the DLL
                if(s -> prev && e -> next){
                    //hence we need to then check if s and e have crossed each other or not
                    /*
                        to check this we can check if any of the pointer like the previous of s is pointing to e
                        or e of next is pointing to s in both cases we need to break as they have crossed each other
                    */

                    if(s -> prev == e && s == e -> next){
                        // cout << "in" << endl;
                        break;
                    }
                }
                ans.push_back({ s -> data, e -> data });
                s = s -> next;
                e = e -> prev;
            }
            // if sum is less than the target then simply move s by 1 as the array is sorted so we need to increase the sum
            else if(sum < target){
                s = s -> next;
            }
            // other wise move e to prev node as the sum is more that the target and we need to decrease the sum
            else{
                e = e -> prev;
            }
        }
        
        
        return ans;
    }
};