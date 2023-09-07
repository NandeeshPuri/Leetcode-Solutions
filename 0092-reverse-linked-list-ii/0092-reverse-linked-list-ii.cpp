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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if(!head || left == right)return head;
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;
        ListNode* temp = newHead;
        ListNode* beforeRev;
        ListNode* afterRev;
        ListNode* lef;
        int count = 0;
        while(temp)
        {
            if(count == left-1)
            {
                lef = temp->next;
                beforeRev = temp;
            }
            if(count == right)
            {
                
                afterRev = temp->next;
                temp->next = NULL;
                break;
            }
            temp = temp->next;
            count++;
        }
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* l = lef;
        while(lef)
        {
            next = lef->next;
            lef->next = prev;
            prev = lef;
            lef = next;
        }
        beforeRev->next = prev;
        l->next = afterRev;
        return newHead->next;
    }
};