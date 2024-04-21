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

    ListNode* FindMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* Merge(ListNode* node1, ListNode* node2) {
        ListNode* sortedList= new ListNode;
        ListNode* temp = sortedList;
        while(node1 != nullptr && node2 != nullptr) {
            if(node1->val > node2->val) {
                temp->next = node2;
                node2 = node2->next;
            } else {
                temp->next = node1;
                node1 = node1->next;
            }
            temp = temp->next;
        }
        if(node1 == nullptr) {
            temp->next = node2;
        }
        if(node2 == nullptr) {
            temp->next = node1;
        }
        // return temp;
        return sortedList->next;
    }

    ListNode* MergeSort(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* middle = FindMiddle(head);
        ListNode* node1 = head;
        ListNode* node2 = middle->next;
        middle->next = nullptr;
        ListNode* sortedList1 = MergeSort(node1);
        ListNode* sortedList2 = MergeSort(node2);
        ListNode* answer = Merge(sortedList1, sortedList2);
        return answer;
    }

    ListNode* sortList(ListNode* head) {
        return MergeSort(head);        
    }
};