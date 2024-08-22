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
    int getLength(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            len++;
            temp = temp -> next;
        }
        return len;
    }

    ListNode* getMiddle(ListNode* head){
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != NULL){
            fast  = fast -> next;

            if(fast != NULL){
                fast = fast -> next;
            }

            slow = slow -> next;
        }
        return slow;
    }

    ListNode* middleNode(ListNode* head) {
        
        return getMiddle(head);

        /*
        int len = getLength(head);
        int midLen = (len/2) + 1;
        int cnt = 1;
        ListNode* temp = head;

        while(cnt < midLen){
            temp = temp -> next;
            cnt++;
        }
        return temp;
        */
    }
};
