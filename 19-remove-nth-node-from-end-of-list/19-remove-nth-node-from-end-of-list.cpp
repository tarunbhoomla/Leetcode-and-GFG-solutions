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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(n==0)
              return head ;
        ListNode* temp = head ;
        int size = 0 ;
        while(temp)
        {
            size++ ;
            temp = temp->next ;
        }
        if(n==size)
        {
            head = head->next ;
            return head ;
        }
        if(n>size)
              return head ;
        
        temp = head; 
        int k = size-n ;
        k = k-1 ;
        while(k--)
        {
            temp = temp->next ;
        }
        if(temp->next->next==NULL)
        {
            temp->next = NULL ;
            return head ;
        }
        
        ListNode* prev = temp ;
        ListNode* ele = temp->next ;
        ListNode* nexxt = NULL ;
        
            
        nexxt = temp->next->next ;
        prev->next = nexxt ;
        
        return head ;
    }
};