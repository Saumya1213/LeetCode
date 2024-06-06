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
    bool hasCycle(ListNode *head) {
        map<ListNode*, int> cnt;

        while(head!=NULL && head->next!=NULL){
            if(cnt.find(head)!=cnt.end()) return true;

            cnt[head]=1;
            head = head->next;
        }

        return false;
    }
};