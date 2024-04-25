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
        map<ListNode*, int> umap;
        while(headA != nullptr) {
            umap[headA] = 1;
            headA = headA->next;
        }
        while(headB != nullptr) {
            if(umap.find(headB) != umap.end()) {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;        
    }
};