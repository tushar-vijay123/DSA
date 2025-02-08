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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;

        // check if k nodes exist
        while(cnt < k){
            if(temp == NULL){
                return head;
            }

            temp = temp->next;
            cnt++;
        }

        // recursive call for rest of the LL
        ListNode* newNext = reverseKGroup(temp, k);

        // reverse nodes for curr call
        temp = head;
        cnt = 0;
        ListNode* nextNode = NULL;
        
        while(cnt < k){
            nextNode = temp->next;
            temp->next = newNext;
            
            newNext = temp;
            temp = nextNode;

            cnt++;
        }

        return newNext;
    }
};
