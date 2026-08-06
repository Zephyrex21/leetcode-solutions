
class Solution {
private:

    ListNode* findmid( ListNode* head ){        // tortose & heir approach to find mid in Linke list

        ListNode* slow = head;
        ListNode* fast = head -> next ;

        while( fast != NULL && fast -> next != NULL ){
            slow = slow -> next ;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* merge( ListNode* left , ListNode* right ){     // merge funct to merge two sorted linked list
    
        if( left == NULL ){
            return right ;
        }

        if( right == NULL ){
            return left ;
        }

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans ;

        // merge two sorted linked list
        while( left != NULL && right != NULL  ){
            
            if( left -> val < right -> val  ){
                temp -> next = left;
                temp = left ;
                left = left -> next;
            }
            else{
                temp -> next = right ;
                temp = right ;
                right = right -> next ;
            }
        }

        while( left != NULL ){
            temp -> next = left;
            temp = left ;
            left = left -> next;
        }

        while( right != NULL ){
            temp -> next = right ;
            temp = right ;
            right = right -> next ;
        }

        ans = ans -> next ;

        return ans;
    }

public:
    ListNode* sortList(ListNode* head) {
        
    // base case 
    if( head == NULL || head -> next == NULL ){
        return head;
    }

    // break linked list into twwo halves
    ListNode* mid = findmid( head );

    ListNode* left = head ;
    ListNode* right = mid -> next ;
    mid -> next = NULL;

    // recursive calls to sort both halves
    left = sortList( left );
    right = sortList( right );

    // merge both left and right halves
    ListNode* result = merge( left , right );

    return result ;
    }
};