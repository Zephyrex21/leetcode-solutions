class Solution {
private:
    ListNode* reverseList( ListNode* head ){

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        
        while( curr != NULL ){
            forward = curr -> next ; 
            curr -> next = prev ;
            prev = curr ;
            curr = forward ;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        
        if( head == NULL || head -> next == NULL ){
            return true;
        }

        // find middle
        ListNode* slow = head ;
        ListNode* fast = head ;

        while( fast -> next != NULL && fast -> next -> next != NULL ){
            slow = slow -> next ;
            fast = fast -> next -> next ;
        }

        // reverse second half
        slow -> next =  reverseList( slow -> next );

        ListNode* first = head ;
        ListNode* second = slow -> next ;

        // compare
        while( second != NULL ){
            if( first -> val != second -> val ){
                return false;
            }
            first = first -> next;
            second = second -> next ;
        }
        return true;
    }
};