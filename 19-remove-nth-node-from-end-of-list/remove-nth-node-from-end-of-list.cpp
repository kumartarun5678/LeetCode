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
        if(head == NULL){
            return head;
        }
       
        ListNode* temp = head;
        ListNode* prev = NULL;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            prev = temp;
            temp = temp->next;
        }
        temp = head;
         if(n ==cnt){
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        for(int i = 1;i<cnt-n;i++){
            temp = temp->next;
        }
       if(temp != NULL && temp->next!=NULL){
            temp->next = temp->next->next;
            // delete temp;
        }
        return head;
    }
};