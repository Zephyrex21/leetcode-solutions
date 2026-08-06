class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    ListNode* head = NULL;
    ListNode* tail = NULL;
    
    int carry = 0;

    while ( l1 != NULL || l2 != NULL || carry != 0 ){

        int val1 = ( l1 != NULL) ? l1->val : 0;
        int val2 = ( l2 != NULL) ? l2->val : 0;

        int sum = val1 + val2 + carry;

        int digit = sum % 10;
        carry = sum / 10;

        ListNode* temp = new ListNode(digit);

        if(head == NULL){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        if( l1 != NULL) l1 = l1->next;
        if( l2 != NULL) l2 = l2->next;
    }
    return head;
    }
};
