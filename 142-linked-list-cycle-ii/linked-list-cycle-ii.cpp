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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int>mp;
        while(head!=NULL){
            if(mp[head]==1) return head;

            mp[head] = 1;

            head=head->next;
        }

        return nullptr;
    }
};