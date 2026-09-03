class Solution {
public:
    Node* flatten(Node* head) {

        if (head == NULL) {
            return head;
        }

        Node* curr = head;

        while (curr != NULL) {

            if (curr->child != NULL) {

                Node* next = curr->next;

                // flatten child list
                Node* child = curr->child;
                curr->next = flatten(child);
                curr->next->prev = curr;

                curr->child = NULL;

                // child list ke last node tak jao
                Node* temp = curr->next;

                while (temp->next != NULL) {
                    temp = temp->next;
                }

                // child list ko original next se connect karo
                temp->next = next;

                if (next != NULL) {
                    next->prev = temp;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};