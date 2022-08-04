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

    
    ListNode* merge(ListNode* left , ListNode* right)
    {
        ListNode* head  = new ListNode(-1) ;
        ListNode* temp = head ;
        while(left && right)
        {
            if(left->val <= right->val )
            {
                temp->next = left ;
                left = left->next ;
                temp = temp->next ;

            }
            else
            {
                temp->next = right ;
                right = right->next ;
                temp = temp->next ;
            }
        }
        if(left)
        {
            temp->next = left ;
        }
        if(right)
        {
            temp->next = right ;
        }
        
        return head->next ;
    }
    ListNode* sortList(ListNode* head) 
    {
        
        if(!head || !head->next)
            return head ;
        
        ListNode* slow = head ;
        ListNode* fast = head ;
        ListNode* temp = NULL;
        
        while(fast != NULL && fast->next!= NULL)
        {
            temp = slow ;
            slow = slow->next ;
            fast = fast->next->next ;
        }
        
        temp->next = NULL ;
        
        ListNode* left = sortList(head) ;
        ListNode* right = sortList(slow) ;
        
        ListNode* res = merge(left ,right) ;
        
        return res ;
    }
};