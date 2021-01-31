https://leetcode.com/problems/sort-list/


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
    ListNode* mergeLists(ListNode* head1, ListNode* head2) {
    ListNode *Head = new ListNode(0);
    ListNode *Tail = Head;
    
    while(head1 && head2){
        if(head1 -> val < head2 -> val){
            Tail -> next = head1;
            head1 = head1 -> next;   
        }
        
        else{
            Tail -> next = head2;
            head2 = head2 -> next;
        }
        Tail = Tail -> next;
    }
    
    if(head1)
        Tail -> next = head1;
    
    
    if(head2)
        Tail -> next = head2;
    

    return Head -> next;
}


    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode *fast = head -> next, *slow = head;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        ListNode *head2 = slow -> next;
        slow -> next = NULL;
        head = sortList(head);
        head2 = sortList(head2);
        head = mergeLists(head, head2);
        return head;
    }
};
