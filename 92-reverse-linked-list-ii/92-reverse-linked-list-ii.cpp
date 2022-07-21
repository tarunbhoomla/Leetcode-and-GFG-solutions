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
// class Solution {
// public:
//     ListNode* reverse(ListNode* head)
//     {
//         ListNode* current = head;
//         ListNode *prev = NULL, *nextt = NULL;
  
//         while (current != NULL) 
//         {
//             nextt = current->next ;
//             current->next = prev ;
//             prev = current ;
//             current = nextt ;
//         }

//         return prev ;
//     }

//     ListNode* reverseBetween(ListNode* head, int left, int right) 
//     {
//         int n = 0 ;
//         ListNode* temp = head ;
//         while(temp)
//         {
//             n++ ;
//             temp = temp->next ;
//         }
        

        
//         if(left >= n || left==right)
//              return head ;
        
//         if(right >= n)
//             right = n ;
//         ListNode* front = head ;
//         ListNode* back = head ;
        
//         for(int i=0 ;i<left-2 ;i++)
//            front = front->next ;
        
//         ListNode* start = front->next ;
        
//         for(int i=0 ;i<right-1 ;i++)
//             back = back->next ;
        
        
//         ListNode* end = back ;
        
//         back = back->next ;
//         end->next = NULL ; 
        
//         ListNode* newHead = reverse(start) ;
//         ListNode*p=newHead;
//         while(p->next)
//             p=p->next;
        
//         front->next = newHead ;
        
//         p->next = back ;
        
//         return head ;
//     }
// };

class Solution
{
    public:
        ListNode* reverseBetween(ListNode *head, int left, int right)
        {
            ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
            dummy->next = head;
            
            for (int i = 0; i < left - 1; i++)
            {
                pre = pre->next;
            }
            
            cur = pre->next;
            
            for (int i = 0; i < right - left; i++)
            {
                ListNode *temp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = temp;
            }
            return dummy->next;
        }
};