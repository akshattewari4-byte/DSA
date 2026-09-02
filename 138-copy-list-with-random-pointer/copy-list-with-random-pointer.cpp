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
        if (head == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> m;

        // First pass: create copy of every node
        Node* oldtemp = head;
        Node* newhead = new Node(oldtemp->val);
        Node* newtemp = newhead;

        m[oldtemp] = newtemp;

        oldtemp = oldtemp->next;

        while (oldtemp != NULL) {
            Node* copy = new Node(oldtemp->val);

            newtemp->next = copy;

            m[oldtemp] = copy;

            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        // Second pass: connect random pointers
        oldtemp = head;
        newtemp = newhead;

        while (oldtemp != NULL) {
            if (oldtemp->random != NULL) {
                newtemp->random = m[oldtemp->random];
            }

            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        return newhead;
    }
};