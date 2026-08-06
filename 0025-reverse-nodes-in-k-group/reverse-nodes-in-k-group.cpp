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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // Base check
        if(head == NULL){
            return NULL;
        }

        // Step 1: check if k nodes exist
        ListNode* temp = head;
        int count = 0;

        while(temp != NULL && count < k){
            temp = temp->next;
            count++;
        }

        if(count < k){
            return head;
        }

        // Step 2: reverse k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        count = 0;

        while(curr != NULL && count < k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        // Step 3: recursion
        head->next = reverseKGroup(forward, k);

        return prev;
    }

};