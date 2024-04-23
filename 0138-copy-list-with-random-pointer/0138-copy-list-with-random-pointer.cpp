/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<Node*> arr1;
        vector<Node*> arr2;
        Node* CloneHead = new Node(0);
        Node* CloneTail = CloneHead;
        while(head != nullptr) {
            CloneTail->next = new Node(head->val);
            CloneTail = CloneTail->next;
            arr1.push_back(head);
            arr2.push_back(CloneTail);
            head = head->next;
        }
        CloneTail = CloneHead->next;
        for(int i=0; i<arr1.size(); i++) {
            if(arr1[i]->random == nullptr) {
                CloneTail->random = nullptr;
            } else {
                for(int j=0; j<arr1.size(); j++) {
                    if(arr1[i]->random == arr1[j]) {
                        CloneTail->random = arr2[j];
                        break;
                    }
                }
            }
            CloneTail = CloneTail -> next; 
        }
        return CloneHead->next;
    }
};