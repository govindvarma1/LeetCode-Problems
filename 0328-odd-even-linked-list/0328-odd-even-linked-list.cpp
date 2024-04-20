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
    ListNode* oddEvenList(ListNode* head) {
        if(head== nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }
        ListNode* node1 = head;
        ListNode* node2 = head->next;
        ListNode* even_node = head->next;
        while(node2 != nullptr && node2->next != nullptr) {
            node1->next = node2->next;
            node2->next = node2->next->next;
            node1 = node1->next;
            node2 = node2->next;   
        }
        node1->next = even_node;
        return head;        
    }
};