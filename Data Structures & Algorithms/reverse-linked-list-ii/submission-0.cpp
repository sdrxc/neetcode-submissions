class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (!head || left == right)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        // Move to left position
        for (int i = 1; i < left; i++) {
            prev = curr;
            curr = curr->next;
        }

        ListNode* connection = prev;
        ListNode* tail = curr;

        // Reverse right-left+1 nodes
        ListNode* next = nullptr;

        for (int i = 0; i < right - left + 1; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Connect the three parts
        connection->next = prev;
        tail->next = curr;

        return dummy->next;
    }
};