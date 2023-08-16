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
    int length(ListNode *head){
        int size=0;
        ListNode *ptr=head;
        while(ptr){
            ptr=ptr->next;
            size++;
        }
        return size;
    }
    ListNode* solve(ListNode* head,int &k,int size){
        if(size<k)return head;

        if(head==NULL)return NULL;

        ListNode *curr=head,*next=NULL,*prev=NULL;
        int cnt=0;
        while(curr!=NULL && cnt<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        head->next=solve(next,k,size-k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=length(head);
        return solve(head,k,n);
    }
};