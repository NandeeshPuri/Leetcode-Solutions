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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode *tempHead=head;
        while(tempHead !=NULL){
            len++;
            tempHead=tempHead->next;
        }

        if(len==n){
            ListNode*newHead=head->next;
            delete head;
            return newHead;
        }

        tempHead=head;
        int travel=len-n-1;
        while (travel > 0) {
            tempHead = tempHead->next;
            travel--;
        }

        ListNode* toDelete = tempHead->next;
        tempHead->next = tempHead->next->next;
        delete toDelete;

        return head;
    }
};