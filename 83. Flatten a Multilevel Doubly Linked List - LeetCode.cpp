/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL){
            return head;
        }

        Node* curr = head;

        while(curr != NULL){
            if(curr->child != NULL){

                Node* nextNode = curr->next;

                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                // connecting tail part back to the parent list
                while(curr->next != NULL){
                    curr = curr->next;
                }
                if(nextNode != NULL){
                    curr->next = nextNode;
                    nextNode->prev = curr;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};
