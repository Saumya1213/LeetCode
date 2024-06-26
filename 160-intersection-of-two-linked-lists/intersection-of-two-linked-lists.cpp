/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int> vis;
        
        while(headA!=NULL){
            vis[headA] = 1;
            headA=headA->next;
        }

        while(headB!=NULL){
            if(vis[headB]==1) return headB;
            vis[headB] = 1;
            headB=headB->next;
        }

        return NULL;
    }
};