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
    ListNode* middleNode(ListNode* head) {
       ListNode *node1=head,*node2=head;
        while(node2->next!=NULL && node2->next->next!=NULL){
            node1=node1->next;
            node2=node2->next->next;
        }
        if(node2->next==NULL){return node1;}
        return node1->next; 
    }
};